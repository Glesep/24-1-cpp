#include <iostream>
using namespace std;

class complex {
    double i,j;

public:
    // 디폴트 생성자가 없었음
    complex() = default;

    complex(int a, int b) {
        i = (double)a;
        j = (double)b;
    }

    complex(double a, double b) {
        i = a;
        j = b;
    }

    complex operator+(complex &c) {
        complex temp;
        temp.i = this->i + c.i;
        temp.j = this->j + c.j;
        return temp;
    }

    complex operator-(complex &c) {
        complex temp;
        temp.i = this->i - c.i;
        temp.j = this->j - c.j;
        return temp;
    }

    complex operator*(complex &c) {
        complex temp;
        temp.i = this->i * c.i + this->j * c.j;
        temp.j = this->i * c.j + this->j * c.i;
        return temp;
    }

    complex operator/(complex &c) {
        complex r (c.i, (-1)*(c.j));
        // 분모 구하기,
        double denominator = c.i*c.i + c.j*c.j;
        complex numerator = (*this) * r;
        
        complex temp(numerator.i / denominator, numerator.j / denominator);
        // 분자 구하기,
        // 분모 나눠주기
        return temp;
    }

    void show() {
        cout << "Complex Number: " << i << " + i " << j << endl;
    }
};

int main() {
    complex c1(1,2);
    complex c2(3,4);
    complex c3 = c1 + c2;
    complex c4 = c1 - c2;
    complex c5 = c1 * c2;
    complex c6 = c1 / c2;
    c3.show();
    c4.show();
    c5.show();
    c6.show();

    return 0;
}