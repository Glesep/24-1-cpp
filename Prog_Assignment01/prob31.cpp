#include <iostream>
using namespace std;

int main()
{
    // 숫자 대입
    int num[7];
    for (int i = 0; i < 7; i++)
        cin >> num[i];

    // Bubble Sort
    for (int i = 6; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (num[j] > num[j+1])
            {
                int tmp = num[j+1];
                num[j+1] = num[j];
                num[j] = tmp;
            }
        }
    }
    
    // 중복된 건 제외
    int k = 0;
    for (int i = 1; i < 7; i++)
    {
        if (num[i] != num[i-1])                           
            num[++k] = num[i];
    }

    // 스트레이트 판정 
    int cnt = 1;
    for (int i = k; i > 0; i--)
    {
        if (num[i] == num[i-1]+1)
            cnt++;
    }

    if (cnt >= 5)
        cout << "YES" << endl;
    else
        cout << "NO" << endl;

    return 0;
}