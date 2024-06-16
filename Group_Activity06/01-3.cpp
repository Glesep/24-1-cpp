#include <iostream>
    
using namespace std;

int main()
{
    float arr[5] = {12.5, 10.0, 13.5, 90.5, 0.5};
    float *ptr1 = &arr[0];
    float *ptr2 = ptr1 + 3;     // "3칸" 차이

    cout << *ptr2 << endl;
    cout << ptr2 - ptr1 << endl;
    
    return 0;
}

/*
90.5
3

배열의 주소 개념 -> 타입이 중간에 변하지 않는 한 인접한 각 배열의 주소의 차이는
"1칸"이다.
*/


