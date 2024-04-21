#include <iostream>
using namespace std;
int main()
{

    int n;
    cin >> n;                                               // 2 <= n <= 30
    int f_n = 0;
    int f_nm1 = 1, f_nm2 = 1;

    for (int i = 0; i < n - 1; i++)
    {
        f_n = f_nm1 + f_nm2;
        if (i == n - 2)                                     // 마지막 반복일 때...
            break;
        f_nm2 = f_nm1;                                      // 반복이 계속된다면 하나씩 밀기
        f_nm1 = f_n;
    }

    cout << f_n << endl;

    return 0;
}

// #include <iostream>
// using namespace std;

// int main() {
//     int n;
//     cin >> n;
//     int prev1 = 1, prev2 = 1, cur;
//     // n이 2부터 출발하니 반복 시작을 i = 2로 설정
//     for (int i = 2; i <= n; i++) {
//         cur = prev1 + prev2;
//         prev2 = prev1;
//         prev1 = cur;
//     }
//     cout << cur;
//     return 0;
// }