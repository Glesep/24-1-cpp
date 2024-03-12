#include <iostream>
using namespace std;
const int MAX = 100;
// Bubble Sort로 내림차순 정리 후, 순서쌍 찾기
// 예제의 의미 모르겠음
int main()
{
    int N;
    cin >> N;

    int num[MAX] = {0};
    
    // 수 입력
    for (int i = 0; i < N; i++)
        cin >> num[i];

    // 기준 값보다 작은 값들만 세기
    int cnt = 0;
    for (int i = 0; i < N-1; i++)
    {
        for (int j = i+1; j < N; j++)
        {
            if (num[i] > num[j])
                cnt++;
        }
    }
    
    cout << cnt << endl;

    return 0;
}
