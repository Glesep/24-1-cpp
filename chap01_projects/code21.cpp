#include <iostream>
using namespace std;

const int MAX = 100;

int main()
{
    int n;
    int data[MAX];
    cin >> n;

    for (int i = 0; i < n; i++)
        cin >> data[i];
    
    int maxSum = data[0];                                   // 합을 나타내는 변수 정의 시 주의! (입력이 주어진 변수들 중 하나 정의)

    for (int i = 0; i < n; i++)                             // 구간의 시작점
    {
        int sum = 0;                                        // 구조 이해

        for (int j = i; j < n; j++)                         // 구간의 끝점
        {
            sum += data[j];
            if (sum > maxSum)
                maxSum = sum;
        }
    }

    cout << "The max sum is " << maxSum << endl;

    return 0;
}
