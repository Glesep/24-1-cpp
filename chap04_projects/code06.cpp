#include <iostream>
#include <cmath>
#include <string>
#include <vector>
using namespace std;



class Point {
public:
    double x, y;
    Point() = default;
    Point(double a, double b): x(a), y(b) {}

    double dist(Point p) {
        return sqrt((x-p.x)*(x-p.x) + (y-p.y)*(y-p.y));
    }
};

class Shape {
private:
    string shape_type;
public:
    Shape() = default;
    Shape(string type): shape_type(type) {}

    string get_type() {
        return shape_type;
    }
    // Virtual 함수 정의
    virtual void print(ostream &out) {
        out << shape_type;
    }
};

class Rect: public Shape {
private:
    Point lu, rl;       // 왼쪽 아래, 오른쪽 위 점들
public:
    Rect() = default;
    Rect(Point a, Point b): Shape("rectangle"), lu(a), rl(b) {}
    Rect(double x1, double y1, double x2, double y2):
                            Shape("rectangle"), lu(Point(x1, y1)), rl(Point(x2, y2)) {}
    // inputStream으로 lu와 rl 초기화
    Rect(istream &in): Shape("rectangle") {
        in >> lu.x >> lu.y >> rl.x >> rl.y;
    }

    double area() { return (rl.x-lu.x) * (rl.y-lu.y); }
    double minx() { return lu.x; }
    double maxx() { return rl.x; }
    double miny() { return lu.y; }
    double maxy() { return rl.y; }

    // Method Overriding
    void print(ostream &out) override {
        Shape::print(out);
        out << ": " << lu.x << " " << lu.y << " " << rl.x << " " << rl.y;
    }
};

class Circle: public Shape {
private:
    Point center;
    double radius;
public:
    Circle() = default;
    Circle(Point a, double r): Shape("circle"), center(a), radius(r) {}
    Circle(double x, double y, double r):
            Shape("circle"), center(Point(x, y)), radius(r) {}
    Circle(istream &in): Shape("circle") {
        in >> center.x >> center.y >> radius;
    }

    // M_PI == 3.141592...
    double area() { return M_PI * radius * radius; }
    double minx() { return center.x-radius; }
    double maxx() { return center.x+radius; }
    double miny() { return center.y-radius; }
    double maxy() { return center.y+radius; }

    // Method Overriding
    void print(ostream &out) override {
        Shape::print(out);
        out << ": " << center.x << " " << center.y << " " << radius;
    }
 
};

int main()
{
    vector<Rect> rvec;
    vector<Circle> cvec;
    string stype;

    while(1) {
        cin >> stype;
        if (stype == "R") {
            Rect r(cin);                //inputStream으로 만드는 생성자 사용
            rvec.push_back(r);
        }
        else if (stype == "C") {
            Circle c(cin);
            cvec.push_back(c);
        }
        else if (stype == "exit")
            break;
    }

    // INT_MAX = int 형식의 가장 큰 값, INT_MIN = int 형식의 가장 작은 값
    double min_x = INT_MAX, max_x = INT_MIN, min_y = INT_MAX, max_y = INT_MIN;

    for (auto &r: rvec) {
        if (r.minx() < min_x) min_x = r.minx();
        if (r.maxx() < max_x) max_x = r.maxx();
        if (r.miny() < min_y) min_y = r.miny();
        if (r.maxy() < min_y) max_y = r.maxy();
    }

    for (auto &c: cvec) {
        if (c.minx() < min_x) min_x = c.minx();
        if (c.maxx() < max_x) max_x = c.maxx();
        if (c.miny() < min_y) min_y = c.miny();
        if (c.maxy() < min_y) max_y = c.maxy();
    }

    cout << min_x << " " << max_x << " " << min_y << " " << max_y << endl;
    return 0;
}