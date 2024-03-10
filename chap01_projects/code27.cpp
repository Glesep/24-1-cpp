#include <iostream>
using namespace std;
const int MAX = 100;

int main()
{
    int n;
    int mat[MAX][MAX];
    cin >> n;

    for (int i = 0; i < n; i++)                     // 행우선 순서로 입력
        for (int j = 0; j < n; j++)
            cin >> mat[i][j]; 

    int row_sum[MAX] = {0}, col_sum[MAX] = {0};

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            row_sum[i] += mat[i][j];                // 하나의 행의 합

    for (int j = 0; j < n; j++)
        for (int i = 0; i < n; i++)
            col_sum[i] += mat[i][j];                // 하나의 열의 합




    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cout << mat[i][j] << " ";                       // 행 출력
        cout << " | " << (double)row_sum[i] / n << endl;    // 행 평균 출력
    }

    for (int j = 0; j < n; j++)
        cout << "--";
    cout << endl;
    for (int j = 0; j < n; j++)
        cout << (double)col_sum[j]/n << " ";                // 열 평균 출력
    cout << endl;

    return 0;
}
