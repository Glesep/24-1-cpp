#include <iostream>
#include <vector>
using namespace std;

class A {
public:
    int data;   // 
    A() {
        cout << "constructor1" << endl;
    }
    A(int a): data(a) {
        cout << "constructor2" << endl;
    }
};

int main() {
    A x, y(10);          
    vector<A> vec_a;    // 타입이 A인 벡터 선언 -> 생성자 작동 X
    vector<A> vec_b(2); // 타입이 A인 벡터 선언 후 크기가 2인 벡터 생성 -> 생성자 작동 O

    return 0;
}

/*
constructor1
constructor2
constructor1
constructor1
*/