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