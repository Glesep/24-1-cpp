#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;

    // N보다 작거나 같으면서 가장 큰 2의 거듭제곱수 v 구하기
    int v = 1;
    while (v * 2 <= N)                      // N과 v*2가 같아도 됨
    {
        v *= 2;
    }

    // 이진수 구하기
    while (v > 0)
    {
        if (N >= v)
        {
            N -= v;
            cout << 1;
        }
        else
            cout << 0;
        
        v /= 2;
    }
    cout << endl;
    
    return 0;
}