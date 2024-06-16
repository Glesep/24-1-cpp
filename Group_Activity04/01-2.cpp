#include <iostream>
    
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

int main()
{
    A arr[3];                   // A타입인 크기가 3인 arr 배열 생성 -> constructor1
    A arr2[4] = {1, 2, 3, 4};   // A 타입인 크기가 4인 arr 배열을 1,2,3,4로 초기화 -> constructor2
    return 0;
}

/*
constructor1
constructor1
constructor1
constructor2
constructor2
constructor2
constructor2
*/