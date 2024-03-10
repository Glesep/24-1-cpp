#include <iostream>
using namespace std;
const int MAX = 100;

int main()
{
    int n;
    cin >> n;

    int data[MAX];
    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
    }

    int s, cnt = 0;
    cin >> s;

    for (int i = 0; i < n - 1; i++)                                 // i < n-1 이어야 하는 이유: j가 i+1이므로
    {
        for (int j = i + 1; j < n; j++)                             // 반복 시작 위치를 잘 생각하기
        {
            if (data[i] + data[j] == s)
                cnt++;
        }
    }

    cout << cnt << endl;
    return 0;
}