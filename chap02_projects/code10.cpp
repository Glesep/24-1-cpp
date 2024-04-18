#include <iostream>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

class MyPoint {
public:
    double x = 0;
    double y = 0;

    // default 생성자
    MyPoint() = default;

    MyPoint(double a, double b): x(a), y(b) {}

    // 이 점의 원점까지의 거리 
    double dist2origin() {
        return sqrt(x*x + y*y);
    }
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

    double dist_center2origin() {
        MyPoint center(lu.x + height/2.0, lu.y + width/2.0);
        return center.dist2origin();
    }

    // 어디로 출력할건지 정하는 매개변수 out (cout / ofstream), ostream은 cout, ofstream의 상위개념, 입출력 스트림들은 무조건 참조에 의한 호출
    void print(ostream &out) {
        out << lu.x << " " << lu.y << " " << width << " " << height;
    }
};

void read_input (istream &source, vector<MyRectangle> &rects);
void sort_by_dist(vector<MyRectangle> &rects);

int main() {
    vector <MyRectangle> rects;
    ifstream infile("rects.txt");
    read_input(infile, rects);
    infile.close();

    sort_by_dist(rects);

    for (MyRectangle r: rects) {
        r.print(cout);
        cout << ": " << r.dist_center2origin() << endl;
    }

    return 0;
}

void read_input (istream &source, vector<MyRectangle> &rects) {
    double x, y, w, h;
    while(source >> x >> y >> w >> h)
        rects.push_back(MyRectangle(x, y, w, h));               // 이름이 없는 MyRectangle 객체 생성
}

void sort_by_dist(vector<MyRectangle> &rects) {
    for (int i = rects.size()-1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            // dist_center2origin의 리턴값은 바로 안 없어지나?
            if (rects[j].dist_center2origin() > 
                                rects[j+1].dist_center2origin())
                swap(rects[j], rects[j+1]);
        }
    }
}