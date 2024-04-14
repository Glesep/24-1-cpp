#include <iostream>
using namespace std;

int Get_Length(int intervals[][2], int index1, int index2);

// 문제에서의 길이 == 진짜 길이
int main()
{
    int N;
    cin >> N;
    int intervals[N][2];

    for (int i = 0; i < N; i++)                     //몇 번째 구간인지 구분
    {
        for (int j = 0; j < 2; j++)                 // 하나의 구간 입력
            cin >> intervals[i][j];
    }

// 구간 비교
/*======================================================================================================================================================================*/
    int length_max = 0, length_now = 0;
    int index_LengthMax1, index_LengthMax2 = 0;
    //[a,b], [c,d]
    for (int i = 0; i < N-1; i++)                       // 기준 폐구간
    {
        for (int j = i+1; j < N; j++)                   // 비교 폐구간
        {
            length_now = Get_Length(intervals, i, j);

            if (length_now > length_max)
            {
                length_max = length_now;
                index_LengthMax1 = i;
                index_LengthMax2 = j;
            }
        }
    }

    cout << "[" << intervals[index_LengthMax1][0] << ", " << intervals[index_LengthMax1][1] << "]" << endl;
    cout << "[" << intervals[index_LengthMax2][0] << ", " << intervals[index_LengthMax2][1] << "]" << endl;
    return 0;
}


// 길이 구하는 함수
int Get_Length(int intervals[][2], int index1, int index2)                    // [a,b], [c,d]
{   
    int length = 0;

    // 1. c<=a<=b<=d : [a,b]가 [c,d] 안에 완전히 포함되는 경우
    if (intervals[index2][0] <= intervals[index1][0] && intervals[index1][1] <= intervals[index2][1])
        length = intervals[index1][1] - intervals[index1][0];
    // 2, a<=c<=d<=b : [c,d]가 [a,b] 안에 완전히 포함되는 경우
    if (intervals[index1][0] <= intervals[index2][0] && intervals[index2][1] <= intervals[index1][1])
        length = intervals[index2][1] - intervals[index2][0];
    
    // 3. a<=c<=b<=d : 두 구간이 일부 겹치는 경우 1
    if (intervals[index1][0] <= intervals[index2][0] && intervals[index1][1] <= intervals[index2][1])
        length = intervals[index1][1] - intervals[index2][0];
    // 4, c<=a<=d<=b : 두 구간이 일부 겹치는 경우 2
    if (intervals[index2][0] <= intervals[index1][0] && intervals[index2][1] <= intervals[index1][1])
        length = intervals[index2][1] - intervals[index1][0];


    return length;
}




// 교수님 풀이

// #include <iostream>
// using namespace std;
// const int MAX = 100;

// int calc_overlap(int s1, int t1, int s2, int t2) {
//     // 안 겹치면 제껴
//     if (t1 <= s2 || t2 <= s1)
//         return 0;
//     // 겹치면 겹치는 부위의 길이 반환
//     return min(t1, t2) - max(s1, s2);
// }

// int main() {
//     int s[MAX], t[MAX], N;
//     cin >> N;
//     for (int i=0; i<N; i++)
//         cin >> s[i] >> t[i];

//     int max_len_overlap = 0;
//     int max_i = 0, max_j = 0;
//     for (int i=0; i<N; i++) {
//         for (int j=i+1; j<N; j++) {
//             int len = calc_overlap(s[i], t[i], s[j], t[j]);
//             if (len > max_len_overlap) {
//                 max_len_overlap = len;
//                 max_i = i, max_j = j;
//             }
//         }
//     }
//     cout << s[max_i] << " " << t[max_i] << " " << s[max_j] << " " << t[max_j];
//     return 0;
// }
