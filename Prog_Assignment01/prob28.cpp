#include <iostream>
using namespace std;
const int MAX = 100;
// 현재 값보다 작은 값이 나오면 오름차순 구간 길이 계산 중지

int main()
{
    int N;
    cin >> N;

    int num[MAX] = {0};
    // 수열 입력
    for (int i = 0; i < N; i++)
        cin >> num[i];
    
    // 오름차순 구간 계산
    int cnt = 1, cnt_max = 0;           // 오름차순에 속해있는 원소의 개수를 구하는 것이므로 cnt = 1 시작
    for (int i = 1; i < N; i++)
    {
        
        // 오름차순이라면...
        if (num[i] >= num[i-1])
            cnt++;
        // 오름차순이 아니라면...
        else
        {
            if (cnt_max < cnt)
                cnt_max = cnt;          // cnt_max 갱신
            
            cnt = 1;                    // cnt 초기화
        }

        if (i == N-1)                   // 마지막 반복일 때...
        {
            if (cnt_max < cnt)
                cnt_max = cnt;
        }
    }

    cout << cnt_max << endl;            // 결과 출력

    return 0;
}