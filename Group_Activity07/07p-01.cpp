// 클래스 B는 클래스 A를 상속받기 때문에 B 객체는 A 객체로 취급될 수 있다.
// 업캐스팅(upcasting): 파생 클래스의 객체를 기본 클래스의 포인터로 가리키는 것
/*
가상 함수가 포함된 클래스는 가상 함수 테이블을 갖는다. 
vtable은 해당 클래스의 객체가 사용할 수 있는 가상 함수들의 포인터를 저장한 테이블이다.
각 객체는 vtable을 가리키는 포인터를 가진다.
가상 함수 호출 시, 이 vtable을 참조하여 올바른 함수가 호출된다.
*/
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
    a = &b;             /*
                            b 객체는 B 클래스의 vtable을 가진다. 
                            따라서 A type인 a 포인터가 b 객체를 가리켜도 
                            B 클래스 내부에서 정의된 함수를 사용한다.
                        */
    a->func();      
    
    return 0;
}
