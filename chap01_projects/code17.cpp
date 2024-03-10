// 배열, 배열의 사용법

#include <iostream>
using namespace std;

const int MAX = 100;                        // define MAX 100(상수 정의)

int main()
{
    int data[MAX];

    int n;
    cin >> n;

    for (int i=0; i<n; i++)
        cin >> data[i];

    int sum = 0, max = data[0];             // 최대값의 초기 정의 == 첫 번째 데이터

    for (int i=0; i<n; i++)
    {
        sum += data[i];
        if (data[i] > max)
            max = data[i];
    }

    cout << "The sum is " << sum << " and the maximum is " << max << endl;

    return 0;
}