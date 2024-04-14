#include <iostream>
using namespace std;
const int MAX = 100;
// 구간 길이를 세다가 합이 K를 넘으면 기존의 cnt_max와 비교 후 cnt, sum = 0으로 초기화

int main()
{
    int N, K;
    cin >> N;

    // 수열 입력받기
    int num[MAX] = {0};
    for (int i = 0; i < N; i++)
        cin >> num[i];
    
    cin >> K;
    
    int sum = 0, cnt = 0, cnt_max = 0;

    for (int i = N-1; i >= 0; i--)
    {
        for (int j = 0; j <= i; j++)
        {
            sum += num[j];
            
            if (sum <= K)                               // sum <= K일 떄 계속 실행
                cnt++;
            else if (sum > K)                           // sum > K일 때 중지
            {
                if (cnt > cnt_max)
                    cnt_max = cnt;
                cnt = 0;
                sum = 0;
            }
        }
        
    }

    cout << cnt_max << endl;

    return 0;
}


//교수님 풀이

// #include <iostream>
// using namespace std;

// const int MAX = 100;

// int main() {
//     int N, K, num[MAX];
//     cin >> N;
//     for (int i=0; i<N; i++)
//         cin >> num[i];
//     cin >> K;
//     int sum = 0, max_len = 0;
//     int s = 0;
//     for (int i=0; i<N; i++) {
//         sum += num[i];
//         while (sum > K)
//             sum -= num[s++];

//         if (i-s+1 > max_len)
//             max_len = i-s+1;
//     }
//     cout << max_len;
//     return 0;
// }