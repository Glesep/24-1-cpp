#include <iostream>
using namespace std;

int main()
{
    int previous = 0, next = 0, num = 0, cnt = 0;

    int n;
    
    
    for (int i = 0; 1 ; i++)
    {
        cin >> n;

        // -1일 때 마지막 값의 전 값과 크기 비교
        if (n == -1)
        {
            if (next <= num)
            cnt ++;

            break;
        }
        // i == 0일 때 (초기값 설정)
        else if (i == 0)
        {
            num = n;
        }

        // i == 1일 때 (초기값의 다음 값과 크기 비교)
        else if (i == 1)
        {
            next = n;
            if (num <= next)
                cnt++;
        }
        
        // 일반적인 극소값 비교
        else
        {
            previous = num;
            num = next;
            next = n;

            if (num <= next && num <= previous)
                cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}