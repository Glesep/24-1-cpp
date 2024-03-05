#include <iostream>
using namespace std;

int main() 
{
    int n;
    int x = 1, factorial = 1;
    cin >> n;

    double sum = 0;

    for (int i = 1; i < n + 1; i++)                                 // n번 반복하면 되므로 분모 팩토리얼 계산을 위해 i는 1부터 n까지
    {
        while (x <= i)                                              // 팩토리얼 계산 (x는 팩토리얼 계산을 위한 변수)
        {
            factorial *= x;
            x++;
        }

        sum += 1 / double(factorial);                               // 합 계산 (이 행에서만 factorial의 type을 double로 변환)
    }

    cout << "RESULT : " << sum << endl;

    return 0;
}