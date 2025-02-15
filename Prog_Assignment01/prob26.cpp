#include <iostream>
using namespace std;
const int MAX = 100;

// n행 2열 (행을 기준으로 구간 입력)
int main()
{
    int n;
    cin >> n;               // 구간 개수

    int intervals[MAX][2] = {0};

    // 구간 입력
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cin >> intervals[i][j];
        }
    }

    // 구간 판정  
    //Bubble Sort, 시작점이 빠른 순서대로 정렬
    for (int i = n-1; i > 0; i--)             
    {
        int tmp = 0;
       
        for (int j = 0; j < i; j++)
        {    // 첫번째 열 비교
            if (intervals[j][0] > intervals[j+1][0])
            {
                tmp = intervals[j][0];
                intervals[j][0] = intervals[j+1][0];
                intervals[j+1][0] = tmp;

                tmp = intervals[j][1];
                intervals[j][1] = intervals[j+1][1];
                intervals[j+1][1] = tmp;
            }
            // 두번째 열 비교
            else if (intervals[j][0] == intervals[j+1][0])
            {
                if (intervals[j][1] > intervals[j+1][1])
                {
                    tmp = intervals[j][1];
                    intervals[j][1] = intervals[j+1][1];
                    intervals[j+1][1] = tmp;
                }
            }

        }
    }

    // 구간 출력
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            cout << intervals[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}


// #include <iostream>
// using namespace std;
// const int MAX = 100;

// int main() {
//     int s[MAX], t[MAX], N;
//     cin >> N;
//     for (int i = 0; i < N; i++)
//         cin >> s[i] >> t[i];

//     for (int i=N-1; i>0; i--) {
//         for (int j=0; j<i; j++) {
//             if (s[j] > s[j+1] || s[j]==s[j+1] && t[j]>t[j+1]) {
//                 int tmp = s[j];
//                 s[j] = s[j+1];
//                 s[j+1] = tmp;
//                 tmp = t[j];
//                 t[j] = t[j+1];
//                 t[j+1] = tmp;
//             }
//         }
//     }

//     for (int i=0; i<N; i++)
//         cout << s[i] << " " << t[i] << endl;
//     return 0;
// }