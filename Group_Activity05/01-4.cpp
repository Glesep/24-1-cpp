#include <iostream>
    
using namespace std;

class A {
    int a = 0;
public:
    A() {
        cout << "Object of A is created\n";
    }
    void show() {
        a++;
        cout << "a: " << a << endl;
    }
};
int main()
{
    A a1, a2;
    // A a3 = a1 + a2;
    return 0;
}

/*
객체끼리의 덧셈은 기본적으로 지원되지 않는다.
*/
