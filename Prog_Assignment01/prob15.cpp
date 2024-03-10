#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int cnt = 0;

    for (int i = 1; i <= N; i++)
    {
        int num = i;                                // i의 값만 들고오기

        //여기서 i를 건들면 외부 for문이 안 끝나요
        while (num > 0)                             // num이 양수일 때, 
        {
            if (num % 10 == 0)                      // num이 10의 배수일 때
            {
                cnt++;                              
            }

            num /= 10;                              // 확인한 수 자르기
        }
    }

    cout << "RESULT : " << cnt << endl;
}