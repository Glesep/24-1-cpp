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

// #include <iostream>
// #include <vector>
// #include <algorithm>
// using namespace std;

// int compare_lex(int a, int b) {
//     int p = 1, q =1;
//     while(p*10 <= a) p*=10;
//     while(q*10 <= b) q*=10;
//     while(p>0 && q>0) {
//         // 맨 앞 자리 확인
//         int d1 = a/p, d2 = b/q;
//         // 앞자리 제외한 자리 저장
//         a %= p, b %= q;
//         // 맨 앞자리 기준 비교
//         if (d1 < d2) return -1;
//         else if (d1 > d2) return 1;
//         p /= 10, q /= 10;
//     }
//     // 자릿수가 다르면
//     if (p>0) return 1;
//     if (q>0) return -1;
//     return 0;
// }

// int main() {
//     vector<int> numbers;
//     int n, k;
//     cin >> n;
//     for (int i=0; i<n; i++) {
//         cin >> k;
//         numbers.push_back(k);
//     }

//     for (int i=n-1; i>0; i--) {
//         for (int j=0; j<i; j++) {
//             if (compare_lex(numbers.at(j), numbers.at(j+1)) > 0)
//                 swap(numbers[j], numbers[j+1]);
//         }
//     }
//     for (int i=0; i<n; i++) {
//         cout << numbers.at(i) << ' ';
//     }

//     return 0;
// }