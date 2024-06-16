#include <iostream>
#include <vector>
using namespace std;

class A
{
public:
    int data;
    A() {
        cout << "constructor1 of A" << endl;
    }
    A(int a): data(a) {
        cout << "constructor2 of A" << endl;
    }
};
class B
{
public:
    vector<A> vec;
    A z;
    B() {
        cout << "constructor1 of B" << endl;
    }
    B(vector<A> v): vec(v) {
        cout << "constructor2 of B" << endl;
    }
};
int main() {
    A x(10);
    vector<A> vec_a;
    A arr[4];
    B y(vec_a);
    return 0;
}
/*
constructor2 of A
-----------------
constructor1 of A
constructor1 of A
constructor1 of A
constructor1 of A
-----------------
constructor1 of A
constructor2 of B


A x(10); -> constructor2 of A

vector<A> vec_a -> A타입 벡터를 선언만 함, 생성자 사용 X

A arr[4]; -> constructor1 of A  X4

B y(vec_a); -> B 생성자 실행
            -> vector<A> vec;  A타입 벡터를 선언만 함, 생성자 사용 X
            -> 클래스 B의 y객체를 생성하면서 멤버변수인 A타입 z객체 생성: constructor1 of A
            -> constructor2 of B 출력

*/
