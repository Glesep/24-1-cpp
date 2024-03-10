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

    for (int j = 0; j < n; j++)                     // 열우선 순서로 출력
    {
        for (int i = 0; i < n; i ++)
            cout << mat[i][j] << " "; 
    }
    cout << endl;
    return 0;
}