#include <iostream>
using namespace std;
// 1. 자릿수 파악
// 2. 자릿수 차이만큼 부족한 쪽에 곱해주기
// 3. 비교

int What_is_faster(int num1, int num2)
{   
    // 1. 자릿수 파악
    int cnt1 = 0, cnt2 = 0;
    int number1 = num1, number2 = num2;
    while(number1 != 0)
    {
        number1 /= 10;
        cnt1++;
    }

    while(number2 != 0)
    {
        number2 /= 10;
        cnt2++;
    }
    
    // 2. 자릿수 맞춰주기
    if (cnt1 - cnt2 < 0)
    {
        for (int i = 0; i < cnt2 - cnt1; i++)
            num1 *= 10;
    }
    else if (cnt1 - cnt2 > 0)
    {
        for (int i = 0; i < cnt1 - cnt2; i++)
            num2 *= 10;
    }

    // 3. 판정
    if (num1 < num2)
        return -1;
    else if (num1 == num2)
        return 0;
    else
        return 1;   
}

int main()
{
    int n;
    cin >> n;
    int num[n];

    for (int i = 0; i < n; i++)
        cin >> num[i];


    //bubble sort 변형
    for (int i = n-1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            // 사전식으로 앞에 것이 늦을 때
            if (What_is_faster(num[j], num[j+1]) == 1)
            {
                int tmp = num[j];
                num[j] = num[j+1];
                num[j+1] = tmp;
            }
            else if (What_is_faster(num[j], num[j+1]) == 0)
            {
                if (num[j] > num[j+1])
                {
                    int tmp = num[j];
                    num[j] = num[j+1];
                    num[j+1] = tmp;
                }
            } 
        }
    }

    for (int i = 0; i < n; i++)
        cout << num[i] << " ";
    cout << endl;

    return 0;
}