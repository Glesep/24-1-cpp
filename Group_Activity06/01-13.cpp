#include <iostream>
    
using namespace std;

class Foo {
public:
    int x;
    Foo() = default;
    Foo(int a): x(a) {}
};

class Bar {
public:
    Foo *ptr;
    int z;
    Bar() = default;
    Bar(Foo *p, int a): ptr(p), z(a) {}
};

int main()
{
    Bar b(new Foo(10), 20);
    cout << (*b.ptr).x << endl;
    cout << b.ptr->x << endl;
    
    return 0;
}

/*
10
10

우선순위 * < .
*/
