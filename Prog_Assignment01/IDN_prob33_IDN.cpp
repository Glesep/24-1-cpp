#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int MAX = 100;
// N은 홀수
// 갔는데 안돼? 돌아와 그냥
// 현재 위치 인덱스 잡기
// 상 좌 하 우 == 1, 2, 3, 4 중 갈 수 있는 곳 cnt로 세기
// 1/cnt가 확률이고 rand함수로 숫자 고르기(시계방향으로 0~3)

int where_we_can_go(int route[][MAX], int index_row, int index_col);

int main()
{
    srand(time(NULL));                                      // 난수 생성기

    int N;
    cin >> N;                                               // N은 홀수를 받음
    int route[MAX][MAX] = {0};

    route[N/2][N/2] = 1;                                    // 처음 위치 (강아지가 가본 곳은 1로 표현)

    // 만번 시도
    int T = 1;
    while (T <= 10000)
    {   
        int index_row = N/2, index_col = N/2;
        while(index_row == 0 || index_row == N-1 || index_col == 0 || index_col == N-1)                 // 가장자리에 갈때까지 함
        {
            int cases = where_we_can_go(route, index_row, index_col);                                   // 갈 수 있는 경우의 수
            
        }
        T++;
    }







    return 0;
}

int where_we_can_go(int route[][MAX], int index_row, int index_col)
{
    int cnt = 0;
    // 시계방향으로 검사
    if (route[index_row-1][index_col] == 0)
        cnt++;
    if (route[index_row][index_col+1] == 0)
        cnt++;
    if (route[index_row+1][index_col] == 0)
        cnt++;
    if (route[index_row][index_col-1] == 0)
        cnt++;

    return cnt;
}