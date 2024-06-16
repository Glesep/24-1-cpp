#include <iostream>
    
using namespace std;

class A {
public:
    int data;
    A(int a): data(a) {}
};

int main()
{
    //A arr[3];
    A arr2[4] = {1, 2, 3, 4};
    
    return 0;
}


/*
디폴트 생성자가 정의되어 있지 않기 때문에
A arr[3]은 오류이다.
*/