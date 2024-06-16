#include <iostream>
#include <vector>
using namespace std;


class A {
public:
    int data;
    A(int a): data(a) {}
};

int main()
{
    // A x;
    A y(10);
    vector<A> vec_a;
    //vector<A> vec_b(2);
    
    return 0;
}

/*
A x;를 하면 디폴트 생성자가 실행이 되어야 하는데 
현재 디폴트 생성자가 선언되어 있지 않으므로 오류이다.

vector<A> vec_b(2);도 위와 같은 이유로 오류이다.

하지만 vector<A> vec_a;는 벡터를 선언만 해주고 실질적인 객체는 만들지 않아
오류가 생기지 않는다.
*/
