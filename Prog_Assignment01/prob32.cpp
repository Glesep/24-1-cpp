#include <iostream>
using namespace std;

// 0을 1로 바꾸고 전체 검사 반복
int main()
{
    int N;
    cin >> N;

    // 0 또는 1 입력
    int bin[N];
    for (int i = 0; i < N; i++)
        cin >> bin[i];
    
    int cnt = 0, cnt_max = 0;
    
    for (int i = 0; i < N; i++)                         // 0을 1로 바꿀까 판정하는 기준인덱스
    {
        int change = 0;
        if (bin[i] == 0)                                // 0이라면...
        {
            bin[i] = 1;
            change = 1;
        }

        // 연속된 1 길이 검사
        for (int j = 0; j < N; j++)                     
        {   

            if (bin[j] == 1)
                cnt++;
            if (bin[j] == 0 || j == N-1)                // 값이 0이거나 마지막 인덱스일 때,
            {
                if (cnt_max < cnt)
                    cnt_max = cnt;
                cnt = 0;
            }
        }
        
        // 바꾼 걸 원상복귀
        if (change == 1)
        {
            bin[i] = 0;                     
        }
    }

    cout << cnt_max << endl;

    return 0;
}


// #include <iostream>
// using namespace std;
// const int MAX = 100;

// int main() {
//     int seq[MAX], N;
//     int forward[MAX] = { 0 }, backward[MAX] = { 0 };
//     cin >> N;
//     for (int i=0; i<N; i++)
//         cin >> seq[i];
//     for (int i=1; i<N; i++) {
//         // 전의 수가 0일 때
//         if (seq[i - 1] == 0)
//             forward[i] = 0;
//         else
//             // 전의 수에서 1 더한 수를 넣기
//             forward[i] = forward[i - 1] + 1;
//     }
//     // 이하 동일
//     for (int i=N-2; i>=0; i--) {
//         if (seq[i + 1] == 0)
//             backward[i] = 0;
//         else
//             backward[i] = backward[i + 1] + 1;
//     }
//     int max = 0;
//     for (int i=0; i<N; i++) {
//         // 앞에서 연속되어서 온 개수와 뒤에서 연속되어서 온 수의 합이 max를 넘는다면
//         if (forward[i]+backward[i] + 1 > max)
//             max = forward[i]+backward[i] + 1;
//     }
//     cout << max;
//     return 0;
// }
