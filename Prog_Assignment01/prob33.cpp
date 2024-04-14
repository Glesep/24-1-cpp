#include <iostream>
#include <cstdlib>
#include <ctime>

const int MAX = 100;

using namespace std;


// 이미 간 곳은 1로 처리하기
bool We_Cannot_Go(int cell[][MAX], int index_row_NOW, int index_col_NOW);
bool We_Arrive(int index_row_NOW, int index_col_NOW, int N);
void Where_We_Go(int cell[][MAX], int& index_row_NOW, int& index_col_NOW);

int main()
{
    srand((unsigned int)time(NULL));

    int N;
    cin >> N;

    
    int trial = 0, success = 0;
    int index_row_NOW = N/2, index_col_NOW = N/2;
    // 갈 수 없을 때 or 도착했을때 반복 종료
    while (trial < 10000)
    {
        int cell[MAX][MAX] = {0};                   // 매번 필드 초기화
        cell[N/2][N/2] = 1;                         // 강아지의 초기 위치

        index_row_NOW = N/2, index_col_NOW = N/2;

        while (!We_Cannot_Go(cell, index_row_NOW, index_col_NOW))
        {
            if (We_Arrive(index_row_NOW, index_col_NOW, N))
            {
                success++;
                break;
            }

            Where_We_Go(cell, index_row_NOW, index_col_NOW);
            cell[index_row_NOW][index_col_NOW] = 1;                         // 도착한 곳을 1로 바꾸기
        }

        trial++;
    }

    cout << (double)success/trial << endl;
    return 0;
}

// 갈 수 없을 때 true, 갈 수 있을 때 false
bool We_Cannot_Go(int cell[][MAX], int index_row_NOW, int index_col_NOW)
{
    return (cell[index_row_NOW-1][index_col_NOW] == 1 && cell[index_row_NOW][index_col_NOW+1] == 1 &&
    cell[index_row_NOW+1][index_col_NOW] == 1 && cell[index_row_NOW][index_col_NOW-1] == 1);
}

bool We_Arrive(int index_row_NOW, int index_col_NOW, int N)
{
    return (index_row_NOW == 0 || index_col_NOW == 0 || index_row_NOW == N-1 || index_col_NOW == N-1);
}

void Where_We_Go(int cell[][MAX], int& index_row_NOW, int& index_col_NOW)               // 한번 시도 (이걸 반복하기)
{
    int TryToGO = rand() % 4;                                                           // 0~3 중 하나
    if (TryToGO == 0 && cell[index_row_NOW-1][index_col_NOW] != 1)                      // 위로 이동을 시도함
    {
        index_row_NOW--;                                                                // 옮기고 main함수에서 1처리해주기
    }    

    else if (TryToGO == 1 && cell[index_row_NOW][index_col_NOW+1] != 1)                 // 오른쪽으로 이동을 시도함                            
    {
        index_col_NOW++; 
    }

    else if (TryToGO == 2 && cell[index_row_NOW+1][index_col_NOW] != 1)                 // 아래로 이동을 시도함
    {
        index_row_NOW++; 
    }

    else if (TryToGO == 3 && cell[index_row_NOW][index_col_NOW-1] != 1)                 // 왼쪽으로 이동을 시도함
    {
        index_col_NOW--; 
    }

}


// #include <iostream>
// #include <cstdlib>
// #include <ctime>
// using namespace std;
// const int MAX = 100;

// void reset();
// bool is_blocked(int x, int y);
// bool feasible_dir(int x, int y, int dir);

// int maze[MAX][MAX], N;;
// int offset[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
// int main() {

//     srand((unsigned int) time(NULL));
//     cin >> N;
//     int count = 0;
//     for (int t=0; t<10000; t++) {
//         int x=N/2, y=N/2;
//         reset();
//         maze[x][y] = 1;
//         bool escaped = false;
//         while(1) {
//             if (x==0 || y==0 || x==N-1 || y==N-1) {
//                 escaped = true;
//                 break;
//             }
//             if (is_blocked(x,y))
//                 break;
//             int dir = rand()%4;
//             if (feasible_dir(x, y, dir)) {
//                 x += offset[dir][0];
//                 y += offset[dir][1];
//                 maze[x][y] = 1;
//             }
//         }
//         if (escaped)
//             count++;
//     }
//     cout << (double)count/10000 << endl;
// }

// void reset() {
//     for (int i=0; i<N; i++)
//         for (int j=0; j<N; j++)
//             maze[i][j] = 0;
// }

// bool feasible_dir(int x, int y, int dir) {
//     int next_x = x+offset[dir][0];
//     int next_y = y+offset[dir][1];

//     if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N
//         && maze[next_x][next_y] == 0)
//         return true;
//     return false;
// }

// bool is_blocked(int x, int y) {
//     for (int d=0; d<4; d++) {
//         if (feasible_dir(x, y, d))
//             return false;
//     }
//     return true;
// }

