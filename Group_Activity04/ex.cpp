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
    A ex;
    ex = obj_a;
    cout << ex.data << endl;
}