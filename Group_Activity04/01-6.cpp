#include <iostream>
#include <vector>
using namespace std;

class A {
public:
    int data;
    A() {
        cout << "constructor1" << endl;
    }
    A(int a): data(a) {
        cout << "constructor2" << endl;
    }
};
class B {
public:
    A mem;
    B(A c) {
        mem = c;
        cout << "B's constructor" << endl;
    }
    
};

int main() {
    A obj_a(2);
    B obj_b(obj_a);
}

/*
constructor2
constructor1
B's constructor

A타입인 C라는 객체를 생성하고 객체 c에 obj_a를 대입하였기 때문에 생성자가 실행된다.
*/