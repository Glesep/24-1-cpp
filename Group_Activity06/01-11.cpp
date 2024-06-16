#include <iostream>
    
using namespace std;

class Foo {
public:
    int x;
    Foo() = default;
    Foo(int a): x(a) {}
};


int main()
{
    Foo f(10);
    Foo *ptr = &f;
    cout << ptr->x << endl;  // 원래는 *f.x
    
    return 0;
}

/*
변수 잘 확인합시다.
*/