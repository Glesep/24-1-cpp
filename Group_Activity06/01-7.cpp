#include <iostream>
    
using namespace std;

void fun(int *p) {
    int q = 10;
    p = &q;                 // 여기 p는 다른 p임
    cout << *p << endl;     // 다른 두 변수가 한 주소를 가리킴
}

int main()
{
    int r = 20;
    int *p = &r;
    fun(p);
    cout << *p;
    
    return 0;
}

/*
** Call by value **
포인터도 값에 의한 매개변수를 받을 수 있음

*/
