#include <iostream>
using namespace std;

int main()
{
    double X = 1, sum = 1; 
    int n;                                          // 지수 n
    cin >> n;

    for (int i = 0; i < n; i++)                     // 거듭제곱 후 합 구하기
    {
        X *= (-0.5);
        sum += X;
    }

    cout << "RESULT : " << sum << endl;
    
    return 0;
}