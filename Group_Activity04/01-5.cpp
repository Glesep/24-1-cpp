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
    B(A c) : mem(c) {
       
        cout << "B's constructor" << endl;
    }
    
};

int main() {
    A obj_a(2);
    B obj_b(obj_a);
}

/*
constructor2
B's constructor

A 타입인 c 객체가 선언됨과 동시에 obj_a로 초기화되기 때문에 생성자가 실행되지 않았다.
*/