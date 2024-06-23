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
    Point midpoint;
    int radius;

public:
    Circle() = default;
    Circle(Point mp, int r) : midpoint(mp), radius(r) {}
};

// 사각형 클래스 Rect
class Rect {
friend class Controller;
private:
    Point leftDown;
    Point rightUp;

public:
    Rect() = default;
    // 조건이 맞을 때 정의되야 함
    Rect(Point ld, Point ru) : leftDown(ld), rightUp(ru) {}
};


class Controller{
private:
    int figureCount;
    vector<Rect> rects;
    vector<Circle> circles;
    vector<Rect>intersectedRects;
    vector<Circle> intersectedCircles;
    Circle circleToCompare;

public:
   
    // 도형의 개수를 세는 함수
    void countFigure(string num) {
        figureCount = stoi(num);
    }

    //사각형 만드는 함수
    Rect makeRect(istream &in) {
        Point ld, ru;
        int tmpX, tmpY;
        // X min
        in >> tmpX;
        ld.set_x(tmpX);
        // X max
        in >> tmpX;
        ru.set_x(tmpX);
        // Y min
        in >> tmpY;
        ld.set_y(tmpY);
        // Y max
        in >> tmpY;
        ru.set_y(tmpY);

        Rect rect(ld, ru);

        return rect;
    }
    // 원 만드는 함수
    Circle makeCircle(istream &in) {
        Point mp;
        int tmpX, tmpY, radius;
        // 중점의 x좌표
        in >> tmpX;
        mp.set_x(tmpX);
        // 중점의 y좌표
        in >> tmpY;
        mp.set_y(tmpY);
        // 반지름 길이
        in >> radius;
        
        Circle circle(mp, radius);

        return circle;
    }

    // 원인지 사각항인지 판단하여 도형을 만든 후 백터에 넣는 함수 (단일)
    void makeCircleOrRect(string data) {

        auto iss = istringstream(data);
        string figure;
        iss >> figure;   
        // 직사각형인 경우
        if (figure == "R") {
            rects.push_back(makeRect(iss));
        }
        // 원인 경우
        else if (figure == "C") {
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

        circleToCompare = makeCircle(infile);
        infile.close();
    }
    
    double dist(int x1, int y1) {
        return sqrt(pow(x1-circleToCompare.midpoint.get_x(), 2) + pow(y1-circleToCompare.midpoint.get_y(), 2));
    }
    
    double rectArea(Rect rect) {
        return ((rect.rightUp.get_x() - rect.leftDown.get_x()) * (rect.rightUp.get_y() - rect.leftDown.get_y()));
    }

    double circleArea(Circle circle) {
        return (pow(circle.radius, 2) * 3.141592);
    }
    
  
    // 비교 대상인 원과 사각형이 교차하는지 확인
    bool isIntersect_Rect(Rect rect) {
        // 직사각형의 꼭짓점이 원 내부에 있는지 확인
        if (dist(rect.leftDown.get_x(), rect.leftDown.get_y()) <= circleToCompare.radius ||
            dist(rect.leftDown.get_x(), rect.rightUp.get_y()) <= circleToCompare.radius  ||
            dist(rect.rightUp.get_x(), rect.rightUp.get_y()) <= circleToCompare.radius   ||
            dist(rect.rightUp.get_x(), rect.leftDown.get_y()) <= circleToCompare.radius ) {
                return true;
            }
        // 원의 중심이 직사각형 내부에 있는지 확인
        if (circleToCompare.midpoint.get_x() >= rect.leftDown.get_x() && circleToCompare.midpoint.get_x() <= rect.rightUp.get_x() &&
            circleToCompare.midpoint.get_y() >= rect.leftDown.get_y() && circleToCompare.midpoint.get_y() <= rect.rightUp.get_y()) {
                return true;
            }
        // 원의 중심과 직사각형의 한 변이 가까운지 확인
        if ((circleToCompare.midpoint.get_x()-rect.rightUp.get_x() <= circleToCompare.radius || rect.leftDown.get_x()-circleToCompare.midpoint.get_x() <= circleToCompare.radius) 
            && circleToCompare.midpoint.get_y() >= rect.leftDown.get_y() && circleToCompare.midpoint.get_y() <= rect.rightUp.get_y() ||
            (circleToCompare.midpoint.get_y()-rect.rightUp.get_y() <= circleToCompare.radius || rect.leftDown.get_y()-circleToCompare.midpoint.get_y() <= circleToCompare.radius)
            && circleToCompare.midpoint.get_x() >= rect.leftDown.get_x() && circleToCompare.midpoint.get_x() <= rect.rightUp.get_x()) {
                return true;
            }
        return false; 


    }
    // 비교 대상인 원과 원이 교차하는지 확인
    bool isIntersect_Circle(Circle circle) {
        if (dist(circle.midpoint.get_x(), circle.midpoint.get_y()) < circle.radius + circleToCompare.radius)
            return true;
        return false; 
    }

    // 비교 대상인 원과 도형이 교차하면 벡터에 넣기
    void intersectFigures() {
        for (auto it = rects.begin(); it < rects.end(); it++) {
            if (isIntersect_Rect(*it)) {
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
    pair<vector<Rect>::iterator, vector<Circle>::iterator> compareArea() {
        
        int minRect = rectArea(*intersectedRects.begin());
        int minCircle = circleArea(*intersectedCircles.begin());
        vector<Rect>::iterator it_RectMin = intersectedRects.begin();
        vector<Circle>::iterator it_CircleMin = intersectedCircles.begin();
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

        pair<vector<Rect>::iterator, vector<Circle>::iterator> p(it_RectMin, it_CircleMin);

        return p;   
    }
    
    // intersected 벡터들에서 최소 사이즈인 도형의 it을 가져옴
    void printIntersectFigures(pair<vector<Rect>::iterator, vector<Circle>::iterator> p) {
        if ((circleArea(*p.second) < rectArea(*p.first) || intersectedRects.size() == 0) && intersectedCircles.size() != 0) {
             cout << "C " << p.second->midpoint.get_x() << " " << p.second->midpoint.get_y() << " " << p.second->radius;
             cout << endl;
             intersectedCircles.erase(p.second);
         }

        if ((circleArea(*p.second) > rectArea(*p.first) || intersectedCircles.size() == 0)&& intersectedRects.size() != 0) {
            cout << "R " << p.first->leftDown.get_x() << " " << p.first->rightUp.get_x() << " "
                         << p.first->leftDown.get_y() << " " << p.first->rightUp.get_y();
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