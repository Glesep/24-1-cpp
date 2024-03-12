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

    // Bubble Sort, 범위 중 최댓값을 맨 끝으로 몰아감
    for (int i = n-1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (data[j] > data[j+1])                        // 현재 인덱스의 값이 다음 인덱스의 값보다 클 때 서로 교환
            {
                int tmp = data[j];
                data[j] = data[j+1];
                data[j+1] = tmp;
            }
        }
    }

    int k = 0;
    // 인덱스 == 1부터 시작, data[0]은 제일 처음 있는 값이므로 중복되는 값이 없음
    for (int i = 1; i < n; i++)
    {
        if (data[i] != data[i-1])                           
            data[++k] = data[i];                            // k의 값을 늘리고 대입
    }

    // 출력
    cout << k+1 << ": ";
    for (int i = 0; i <= k; i++)
        cout << data[i] << " ";
    cout << endl;

    return 0;
}