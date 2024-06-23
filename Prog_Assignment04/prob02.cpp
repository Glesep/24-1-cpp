#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <fstream>
using namespace std;

// 점 클래스 Point
class Point {
private:
    int x;
    int y;

public:
    Point() = default;

    Point(int xi, int yi): x(xi), y(yi) {}
    Point(double xd, double yd): x(xd), y(yd) {}

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

// 사각형 클래스 Rect
class Rect {
// private를 보여주는 곳에서 보여줄 곳을 지정
friend class Controller;
private:
    Point leftDown;
    Point rightUp;

public:
    Rect() = default;
    // 조건이 맞을 때 정의되야 함
    Rect(Point ld, Point ru) : leftDown(ld), rightUp(ru) {}
};

class Controller {
private: 
    int figureCount;
    vector<Rect> rects;

public:

    // 도형 수 세기
    void countFigure(string num) {
        figureCount = stoi(num);
    }

    // Rect 객체 만들기
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

    // 벡터 안에 rect 객체 넣기
    void putRects(string data) {

        auto iss = istringstream(data);  
        
        rects.push_back(makeRect(iss));
    }

    // 파일 안 사각형 불러오는 함수
    void makeRectInFile() {
        ifstream infile("input2.txt");

        string data;
        // getline과 infile >> 혼용시 에러 생기기 쉬움
        // infile >> 는 \n도 받아오는 것 같음
        getline(infile, data);
        // 도형 개수 받아오기
        countFigure(data);

        // 파일 안에 있는 도형 전체를 받아오기
        for (int i = 0; i < figureCount; i++) {
            getline(infile, data);
            putRects(data);
        }

        infile.close();
    }

    // 모든 사각형을 포함하는 가장 작은 사각형 찾기
    Rect findTangentRect() {
        int left = rects.begin()->leftDown.get_x();
        int right = rects.begin()->rightUp.get_x();
        int up = rects.begin()->rightUp.get_y();
        int down = rects.begin()->leftDown.get_y();
        
        for (auto it = rects.begin()+1; it < rects.end(); it++) {
            // 가장 왼쪽인 x좌표 찾기
            if (it->leftDown.get_x() < left) 
                left = it->leftDown.get_x();
            // 가장 아래쪽인 y좌표 찾기
            if (it->leftDown.get_y() < down)
                down = it->leftDown.get_y();
            // 가장 오른쪽인 x좌표 찾기
            if (it->rightUp.get_x() > right)
                right = it->rightUp.get_x();
            // 가장 위쪽인 y좌표 찾기
            if (it->rightUp.get_y() > up)
                up = it->rightUp.get_y();
        }

        Point LD(left, down);
        Point RU(right, up);

        Rect tangentRect(LD, RU);

        return tangentRect;
    }

    // 가장 작은 원 찾는 함수
    void findSmallestCircle() {
        // 모든 사각형을 포함하는 가장 작은 사각형
        Rect tangentRect = findTangentRect();
        
        // tangentRect의 대각선을 지름으로
        double radius = sqrt(pow(tangentRect.leftDown.get_x() - tangentRect.rightUp.get_x(), 2) 
                                + pow(tangentRect.leftDown.get_y() - tangentRect.rightUp.get_y(), 2));

        Point mp(((double)tangentRect.leftDown.get_x() + tangentRect.rightUp.get_x())/2, 
                   ((double)tangentRect.leftDown.get_y() + tangentRect.rightUp.get_y())/2);

        cout << "Middle Point: (" << mp.get_x() << ", " <<  mp.get_y() << ")" << endl;
        cout << "Radius: " << radius / 2 << endl;
    }

};

int main() {
    Controller controller;
    controller.makeRectInFile();
    controller.findSmallestCircle();

    return 0;
}