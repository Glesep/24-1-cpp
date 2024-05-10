#include <iostream>
using namespace std;


class A {
public: 
    // 스태틱 변수.. 그 자리에서 항상 남아있음..
    static int a;
    void show() {
        a++;
        cout << "a: " << a << endl;
    }
};

int A::a = 5;

int main() {
    A a, b;
    a.show();               // a++ -> a == 6, 클래스 A의 a도 6 (static 변수이므로)
    cout << A::a << endl;   // a == 6

    b.a = 10;               // b.a = 10 -> a a== 10, 클래스 A의 a 도 10
    cout << a.a << endl;    // static변수이므로 모든 클래스가 공유 -> a.a == 10

    return 0;

}