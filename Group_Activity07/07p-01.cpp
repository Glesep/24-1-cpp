#include <iostream>
using namespace std;

class A {
    double d;
public:
    virtual void func() {
        cout << "In class A\n";
    }
};

class B: public A {
    int a = 15;
public:
    void func() {
        cout << "In class B\n";
    }
};

int main()
{
    A *a = new A();
    B b;
    a = &b;         // 포인터에 타입이 있는 이유는 컴퓨터에 메모리 공간을 얼마나 할당해야 하는지 알려주기 위함이다.
    a->func();      
    
    return 0;
}
