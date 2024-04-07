#include <iostream>
using namespace std;
const int MAX = 100;

int main()
{
    int n, k;
    int data[MAX];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> data[i];

    int count = 1, max_count = 1;
    for (int i = 1; i<n; i++) {
        if (data[i] == data[i - 1])             // 현재 값과 그 전 값이 같을 때,
            count++;
        else                                    // 현재 값과 그 전 값이 다를 때,
            count = 1;                          // 1로 초기화  
        if (count > max_count)
            max_count = count;
    }

    cout << max_count << endl;
    return 0;



    // int n;
    // cin >> n;
    // int data[MAX];
    
    // for (int i = 0; i < n; i++)
    //     cin >> data[i];

    // int maxCnt = 0;

    // for (int i = 0; i < n - 1; i++)
    // {
    //     int cnt = 1;

    //     for (int j = i + 1; j < n; j++)
    //     {
    //         if (data[i] == data[j])
    //             cnt++;
    //     }
        
    //     if (cnt > maxCnt)
    //         maxCnt = cnt;
    // }

    // cout << "The maxCnt is " << maxCnt << endl;
}