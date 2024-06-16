#include <iostream>
#include <vector>
using namespace std;

class Foo {
public:
    int x;
    Foo() = default;
    Foo(int a): x(a) {}
};

int main()
{
    vector<Foo *> vec {new Foo(1), new Foo(2),
                    new Foo(3), new Foo(4)};
    
    auto it = vec.begin() + 2;
    cout << (*it) -> x << endl;
    
    
    return 0;
}

/*
3

이터레이터의 포인터처럼 하는 역할 
*/
