#include <iostream>
    
using namespace std;

int main()
{
    int arr[10];
    arr[0] = 10;
    int *ptr = &arr[0]; // 원래는 arr[0]
    arr[1] = 20;
    arr[0] = 30;
    cout << *ptr << endl;
    
    return 0;
}

/*
ptr은 포인터 변수이므로 주소를 넣어줘야 한다.
*/