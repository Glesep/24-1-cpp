#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

class MyPoint {
public:
    double x;
    double y;

    // 생성자
    MyPoint(double a, double b): x(a), y(b) {}
};

class MyRectangle {
public:
    MyPoint lu;
    double width, height;

    // lu = p로 대입
    MyRectangle(MyPoint p, double w, double h): lu(p), width(w), height(h) {}
    // 생성자로 x,y를 받아 lu 객체 생성
    MyRectangle(double x, double y, double w, double h): lu(x,y), width(w), height(h) {}

    // 어떤 점이 사각형 안에 속하는가
    bool contains(MyPoint p) {
        return p.x >= lu.x && p.x <= lu.x + height && p.y >= lu.y
                        && p.y <= lu.y + width;
    }

    double area() {
        return width * height;
    }
};

int main() {
    vector<MyRectangle> rects;
    ifstream infile("rects.txt");
    double x, y, w, h;
    while (infile >> x >> y >> w >> h) {
        MyRectangle r(x, y, w, h);
        rects.push_back(r);
    }
    infile.close();

    cin >> x >> y;
    MyPoint p(x, y);
    for (auto r : rects) {
        if (r.contains(p)) {
            cout << r.lu.x << " " << r.lu.y << " " << r.width << " " << r.height << endl;
        }
    }
    return 0;
}



// int main() {
//     vector<MyRectangle> rects;
//     ifstream infile("rects.txt");
//     double x, y, w, h;
//     while (!infile.eof()) {             // 파일에 '\n' 만 남아 있어도 eof는 false를 반환함
//         infile >> x >> y >> w >> h;     // 여기는 읽을 데이터가 없어서 false가 리턴되지만 아무도 신경쓰지 않음
//         MyRectangle r(x, y, w, h);      // 따라서 전에 저장되어있던 변수로 실행되어버림
//         rects.push_back(r);
//     }
//     infile.close();

//     cin >> x >> y;
//     MyPoint p(x, y);
//     for (auto r : rects) {
//         if (r.contains(p)) {
//             cout << r.lu.x << " " << r.lu.y << " " << r.width << " " << r.height << endl;
//         }
//     }
//     return 0;
// }