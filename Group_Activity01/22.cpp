#include <iostream>
using namespace std;

// 22번
// 배열의 이름 == 포인터로 정의, 따라서 포인터 변수로 배열의 이름을 받으면 배열의 주소가 같기 때문에 배열의 각 요소에 접근 가능
int main()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
    int* b;
    b = a; 
    for (int i=0; i<10; i++) 
        cout << b[i] << " " << endl; 
    
}