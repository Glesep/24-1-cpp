#include <iostream>
using namespace std;

class MyPoint {
public:
    double x, y;
    MyPoint() {
        cout << "MyPoint Created!" << endl;
    };

    MyPoint(double a, double b) : x(a), y(b) {};
};

class MyRectangle {
public:
    MyPoint lu;

};

int main() {
    MyRectangle r;
}