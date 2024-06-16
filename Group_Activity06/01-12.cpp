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
    Foo *f = new Foo(20);
    cout << f->x << endl;    
    
    return 0;
}

/*
20
*/
