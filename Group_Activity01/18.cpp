#include <iostream>
using namespace std;


// 18번 hello3 출력횟수 : (n-1)n/2
// 18번 hello4 출력횟수 : n(n+1)/2

// 결과 확인을 위해 n == 5를 대입했습니다.
int main()
{
    int cnt3 = 0, cnt4 = 0;

    for (int i=0; i < 5; i++)                   // n번 반복
        for (int j=0; j<i; j++)                 // i == 0일 때는 실행 안됨, i == 1일때부터 i == n-1까지 반복하고 반복 횟수는 i의 값과 같다
            cnt3++;
    cout << cnt3 << endl;

    for (int i=5-1; i>=0; i--)                  // n번 반복           
        for (int j=0; j<=i; j++)                // i+1번 반복하므로 중첩 for문은 n, n-1, n-2, ... 2, 1 번씩 각각 반복
            cnt4++;

    cout << cnt4 << endl;
}