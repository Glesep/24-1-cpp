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

// 추상 클래스: 순수 가상 함수가 있는 클래스
class Shape {
private:
    string shape_type;
public:
    Shape() = default;
    Shape(string type): shape_type(type) {}

    string get_type() {
        return shape_type;
    }
    // 순수 Virtual 함수 정의
    virtual void print(ostream &out) {
        out << shape_type;
    }

    virtual double area() = 0;
    virtual double minx() = 0;
    virtual double maxx() = 0;
    virtual double miny() = 0;
    virtual double maxy() = 0;
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

    // 순수 가상 함수를 여기서 구체적으로 정의해주지 않으면 이 클래스도 추상 클래스가 된다.
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

    // 순수 가상 함수를 여기서 구체적으로 정의해주지 않으면 이 클래스도 추상 클래스가 된다.
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
    vector<Shape *> vec;
    string stype;

    while(1) {
        cin >> stype;
        if (stype == "R") {
            Rect *r = new Rect(cin);                //inputStream으로 만드는 생성자 사용
            vec.push_back(r);                       // 다형성 덕분에 Rect 객체를 base class인 Shape의 포인터 타입으로 받을 수 있다.
        }
        else if (stype == "C") {
            Circle *c = new Circle(cin);
            vec.push_back(c);                       // 다형성 덕분에 Circle 객체를 base class인 Shape의 포인터 타입으로 받을 수 있다.
        }
        else if (stype == "exit")
            break;
    }


    // INT_MAX = int 형식의 가장 큰 값, INT_MIN = int 형식의 가장 작은 값
    double min_x = INT_MAX, max_x = INT_MIN, min_y = INT_MAX, max_y = INT_MIN;

    for (auto &s: vec) {
        if (s->minx() < min_x) min_x = s->minx();
        if (s->maxx() < max_x) max_x = s->maxx();
        if (s->miny() < min_y) min_y = s->miny();
        if (s->maxy() < min_y) max_y = s->maxy();
    }

    cout << min_x << " " << max_x << " " << min_y << " " << max_y << endl;
    return 0;
}