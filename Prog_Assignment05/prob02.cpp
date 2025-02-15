// 원과 사각형을 표현하는 객체들은 동적 생성된 객체 사용

#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <fstream>
#include <string>
using namespace std;

// 점 클래스 Point
class Point {
private:
    int x;
    int y;

public:
    int get_x() {
        return x;
    }
    
    void set_x(int x2) {
        x = x2;
    }

    int get_y() {
        return y;
    }

    void set_y(int y2) {
        y = y2;
    }
};

// 원 클래스 Circle
class Circle {
friend class Controller;
private: 
    Point *midpoint;
    int radius;

public:
    Circle() = default;
    Circle(Point *mp, int r) : midpoint(mp), radius(r) {}
    ~Circle() {
        delete midpoint;        // midpoint 동적 객체 삭제
    }
};

// 사각형 클래스 Rect
class Rect {
friend class Controller;
private:
    Point *leftDown;
    Point *rightUp;

public:
    Rect() = default;
    // 조건이 맞을 때 정의되야 함
    Rect(Point *ld, Point *ru) : leftDown(ld), rightUp(ru) {}
    ~Rect() {
        delete leftDown;
        delete rightUp;
    }
};

// ======================================================Controller=====================================================================
// 도형 객체들은 동적 할당받을 것!!!
class Controller{
private:
    int figureCount;
    vector<Rect *> rects;
    vector<Circle *> circles;
    vector<Rect *>intersectedRects;
    vector<Circle *> intersectedCircles;
    Circle *circleToCompare;

    void clearMembers() {
        delete circleToCompare;

        for (auto p: rects)
            delete p;
        rects.clear();

        for (auto p: circles)
            delete p;
        circles.clear();
    }

public:
    ~Controller() {
        clearMembers();
    }

    // 도형의 개수를 세는 함수
    void countFigure(string num) {
        figureCount = stoi(num);
    }

    //사각형 만드는 함수
    Rect *makeRect(istream &in) {
        Point *ld = new Point();
        Point *ru = new Point();
        int tmpX, tmpY;
        // X min
        in >> tmpX;
        ld->set_x(tmpX);
        // X max
        in >> tmpX;
        ru->set_x(tmpX);
        // Y min
        in >> tmpY;
        ld->set_y(tmpY);
        // Y max
        in >> tmpY;
        ru->set_y(tmpY);

        Rect *rect = new Rect(ld, ru);          // ld, ru를 여기서 지워버리면 안됨!! leftDown, rightUp 포인터가 가리키는 객체가 없어져버림

        // 동적 할당된 변수의 주소 반환
        return rect;
    }

    // 원 만드는 함수
    Circle *makeCircle(istream &in) {
        // 항상 동적할당 먼저 해주기
        Point *mp = new Point();
        
        int tmpX, tmpY, radius;
        // 중점의 x좌표
        in >> tmpX;
        mp->set_x(tmpX);
        // 중점의 y좌표
        in >> tmpY;
        mp->set_y(tmpY);
        // 반지름 길이
        in >> radius;
        
        Circle *circle = new Circle(mp, radius);        // mp를 여기서 지워버리면 안됨!! midPoint 포인터가 가리키는 객체가 없어져버림
        
        // 주소 반환
        return circle;
    }

    // 원인지 사각항인지 판단하여 도형을 만든 후 백터에 넣는 함수 (단일)
    void makeCircleOrRect(string data) {

        auto iss = istringstream(data);
        string figure;
        iss >> figure;   
        // 직사각형인 경우
        if (figure == "R") {
            // 동적 할당된 객체의 주소를 저장하는 벡터 rects
            rects.push_back(makeRect(iss));
        }
        // 원인 경우
        else if (figure == "C") {
            // 동적 할당된 객체의 주소를 저장하는 벡터 circles
            circles.push_back(makeCircle(iss));
        }

    }

    void makeCircleOrRectInFile() {
        ifstream infile("input1.txt");

        string data;
        // getline과 infile >> 혼용시 에러 생기기 쉬움
        // infile >> 는 \n도 받아오는 것 같음
        getline(infile, data);
        // 도형 개수 받아오기
        countFigure(data);

        // 파일 안에 있는 도형 전체를 받아오기
        for (int i = 0; i < figureCount; i++) {
            getline(infile, data);
            makeCircleOrRect(data);
        }

        // 맨 마지막으로 주어진 원 객체의 포인터
        circleToCompare = makeCircle(infile);
        infile.close();
    }
    
    double dist(int x1, int y1) {
        return sqrt(pow(x1-circleToCompare->midpoint->get_x(), 2) + pow(y1-circleToCompare->midpoint->get_y(), 2));
    }
    
    double rectArea(Rect *rect) {
        return ((rect->rightUp->get_x() - rect->leftDown->get_x()) * (rect->rightUp->get_y() - rect->leftDown->get_y()));
    }

    double circleArea(Circle *circle) {
        return (pow(circle->radius, 2) * 3.141592);
    }
    
  
    // 비교 대상인 원과 사각형이 교차하는지 확인
    bool isIntersect_Rect(Rect *rect) {
        if (dist(rect->leftDown->get_x(), rect->leftDown->get_y()) <= circleToCompare->radius ||
            dist(rect->leftDown->get_x(), rect->rightUp->get_y()) <= circleToCompare->radius  ||
            dist(rect->rightUp->get_x(), rect->rightUp->get_y()) <= circleToCompare->radius   ||
            dist(rect->rightUp->get_x(), rect->leftDown->get_y()) <= circleToCompare->radius ) {
                return true;
            }
        
        if (circleToCompare->midpoint->get_x() >= rect->leftDown->get_x() && circleToCompare->midpoint->get_x() <= rect->rightUp->get_x() &&
            circleToCompare->midpoint->get_y() >= rect->leftDown->get_y() && circleToCompare->midpoint->get_y() <= rect->rightUp->get_y()) {
                return true;
            }

        if ((circleToCompare->midpoint->get_x()-rect->rightUp->get_x() <= circleToCompare->radius || rect->leftDown->get_x()-circleToCompare->midpoint->get_x() <= circleToCompare->radius) 
            && circleToCompare->midpoint->get_y() >= rect->leftDown->get_y() && circleToCompare->midpoint->get_y() <= rect->rightUp->get_y() ||
            (circleToCompare->midpoint->get_y()-rect->rightUp->get_y() <= circleToCompare->radius || rect->leftDown->get_y()-circleToCompare->midpoint->get_y() <= circleToCompare->radius)
            && circleToCompare->midpoint->get_x() >= rect->leftDown->get_x() && circleToCompare->midpoint->get_x() <= rect->rightUp->get_x()) {
                return true;
            }
        return false; 


    }
    // 비교 대상인 원과 원이 교차하는지 확인
    bool isIntersect_Circle(Circle *circle) {
        if (dist(circle->midpoint->get_x(), circle->midpoint->get_y()) < circle->radius + circleToCompare->radius)
            return true;
        return false; 
    }

    // 비교 대상인 원과 도형이 교차하면 벡터에 넣기
    // intersectedRects는 rects와 사각형 객체를 공유 -> 굳이 intersectedRects에서 Garbage 고려 안해도 됨
    void intersectFigures() {
        for (auto it = rects.begin(); it < rects.end(); it++) {
            //*it == 포인터 변수
            if (isIntersect_Rect(*it)) {
                // 해당 조건을 만족하는 벡터가 들어감
                intersectedRects.push_back(*it);
            }
        }

        for (auto it = circles.begin(); it < circles.end(); it++) {
            if (isIntersect_Circle(*it)) {
                intersectedCircles.push_back(*it);
            }
        }
    }
    // 면적 비교
    pair<vector<Rect *>::iterator, vector<Circle *>::iterator> compareArea() {
        vector<Rect *>::iterator it_RectMin;
        vector<Circle *>::iterator it_CircleMin; 

        int minRect = rectArea(*intersectedRects.begin());
        int minCircle = circleArea(*intersectedCircles.begin());
        it_RectMin = intersectedRects.begin();
        it_CircleMin = intersectedCircles.begin();
        for (auto it = intersectedRects.begin(); it < intersectedRects.end(); it++) {
            if (rectArea(*it) < minRect) {
                minRect = rectArea(*it);
                it_RectMin = it;
            }
        }

        for (auto it = intersectedCircles.begin(); it < intersectedCircles.end(); it++) {
            if (circleArea(*it) < minCircle) {
                minCircle = circleArea(*it);
                it_CircleMin = it;
            }
        }

        pair<vector<Rect *>::iterator, vector<Circle *>::iterator> p(it_RectMin, it_CircleMin);

        return p;   
    }

    void printIntersectFigures(pair<vector<Rect *>::iterator, vector<Circle *>::iterator> p) {
        // p.second == circle 포인터벡터의 이터레이터, p.first == rect 포인터벡터의 이터레이터
        // *p.second == circle 포인터 벡터, *p.first == rect 포인터 벡터
        // *보다 -> 가 더 우선순위 높음
        // intersectedCircles, intersectedRects는 각각 circles, rects와 도형 객체를 공유하기 때문에 Garbage 신경 안써도 됨
        if ((circleArea(*p.second) < rectArea(*p.first) || intersectedRects.size() == 0) && intersectedCircles.size() != 0) {
            
             cout << "C " << (*p.second)->midpoint->get_x() << " " << (*p.second)->midpoint->get_y() << " " << (*p.second)->radius;
             cout << endl;
             intersectedCircles.erase(p.second);
         }

        if ((circleArea(*p.second) > rectArea(*p.first) || intersectedCircles.size() == 0) && intersectedRects.size() != 0) {
            cout << "R " << (*p.first)->leftDown->get_x() << " " << (*p.first)->rightUp->get_x() << " "
                         << (*p.first)->leftDown->get_y() << " " << (*p.first)->rightUp->get_y();
            cout << endl;
            intersectedRects.erase(p.first);
        }
    }

    void printResult() {
        intersectFigures();
        while(1) {
            printIntersectFigures(compareArea());
            
            if (intersectedRects.size() == 0 && intersectedCircles.size() == 0)
                break;
        }
    }
};


int main() {
    Controller controller;
    controller.makeCircleOrRectInFile();
    controller.printResult();

    return 0;
}