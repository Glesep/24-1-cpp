#include <iostream>
#include <cmath>
#include <ctime>

const int MAX = 100;

using namespace std;

// 움직이면 true, 안움직이면 false 출력하도록
// 무작위 위치로 움직이기, 이미 1인 곳이었다면 안되면 다시 돌아와
// 이미 간 곳은 1로 처리하기
bool We_Cannot_Go(int cell[][MAX], int index_row_NOW, int index_col_NOW);
bool We_Arrive(int index_row_NOW, int index_col_NOW, int N);
void Where_We_Go(int cell[][MAX], int& index_row_NOW, int& index_col_NOW);

int main()
{
    srand(time(NULL));

    int N;
    cin >> N;

    int cell[MAX][MAX] = {0};                   // 안간 곳들은 0 표시

    cell[N/2][N/2] = 1;                         // 강아지의 초기 위치

    int index_row_NOW = N/2, index_col_NOW = N/2;
    int success = 0, trial = 0;
    // 갈 수 없을 때 or 도착했을때 반복 종료
    while (trial < 10000)
    {
        while (!We_Cannot_Go(cell, index_row_NOW, index_col_NOW))
        {
            if (We_Arrive(index_row_NOW, index_col_NOW, N))
            {
                success++;
                break;
            }

            Where_We_Go(cell, index_row_NOW, index_col_NOW);
        }

        trial++;
    }

    cout << success << " " << trial << endl;
    cout << (double)success/trial << endl;
    return 0;
}

// 갈 수 없을 때 true, 갈 수 있을 때 false
bool We_Cannot_Go(int cell[][MAX], int index_row_NOW, int index_col_NOW)
{
    return (cell[index_row_NOW-1][index_col_NOW] == 0 && cell[index_row_NOW][index_col_NOW+1] == 0 &&
    cell[index_row_NOW+1][index_col_NOW] && cell[index_row_NOW][index_col_NOW-1]);
}

bool We_Arrive(int index_row_NOW, int index_col_NOW, int N)
{
    return (index_row_NOW == 0 || index_col_NOW == 0 || index_row_NOW == N-1 || index_col_NOW == N-1);
}

void Where_We_Go(int cell[][MAX], int& index_row_NOW, int& index_col_NOW)           // 한번 시도 (이걸 반복하기)
{
    int TryToGO = rand() % 4;                                                       // 0~3 중 하나
    if (TryToGO == 0 && cell[index_row_NOW-1][index_col_NOW] != 1)                  // 위로 이동을 시도함
    {
        index_row_NOW--;                                                            // 옮기고 main함수에서 1처리해주기
    }    

    else if (TryToGO == 1 && cell[index_row_NOW][index_col_NOW+1] != 1)                  // 오른쪽으로 이동을 시도함                            
    {
        index_col_NOW++; 
    }

    else if (TryToGO == 2 && cell[index_row_NOW+1][index_col_NOW] != 1)                  // 아래로 이동을 시도함
    {
        index_row_NOW++; 
    }

    else if (TryToGO == 3 && cell[index_row_NOW][index_col_NOW-1] != 1)                  // 왼쪽으로 이동을 시도함
    {
        index_col_NOW--; 
    }

}