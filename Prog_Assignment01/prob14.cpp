#include <iostream>
using namespace std;

int gcd(int big, int small);

// (i, j, k)
int main()
{
    int cnt = 0;
    for (int i = 2; i <= 100; i++)
    {
        for (int j = i+1; j <= 100; j++)
        {
            for (int k = j+1; k <= 100; k++)
            {
                // 서로소는 공약수가 1밖에 없을 때를 의미
                if (gcd(i, j) == 1 && gcd(j, k) == 1 && gcd(i, k) == 1)                 // 모든 정수쌍에 대해 서로소 확인
                    cnt++;   
            }
        }  
    }

    cout << cnt << endl;
    return 0;
}


// 유클리드 호제법 알아놓기
int gcd(int big, int small)
{
    while (small != 0)
    {
        int tmp = big;
        big = small;
        small = tmp % small;
    }
    return big;
}