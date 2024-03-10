#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int digit[10] = {0,};                                   // 배열 내부 값 0으로 초기화 (초기화 안하면 오류남)
    
    while (N > 0)
    {
        for (int i = 0; i < 10; i++)
        {
            
            if (N % 10 == i)
            {
                digit[i]++;
                
            }
        }

        N /= 10;
    }
    
    for (int i = 0; i < 10; i++)
    {
        if (i == 9)
            cout << digit[i] << endl;
        else
            cout << digit[i] << ", ";
    }

    return 0;
}