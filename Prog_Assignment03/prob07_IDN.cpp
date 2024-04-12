#include <iostream>
#include <vector>
using namespace std;
// 4,5행에 초기 바둑돌
// 둔 곳 기준으로 전 방향 검사, 동일 색 돌이 나왓으면 그 사이 색 다 바꾸기

// 8x8 바툭판
vector<vector<int>> board(8, vector<int>(8,0));


int main() {
    board[4][4] = 1;                // black
    board[4][5] = 2;                // white
    board[5][4] = 2;
    board[5][5] = 1;



    return 0;
}

int countStoneToCapture(int x, int y, int color) {
    int count = 0;
    for (int i = x-1; i >= 0; i--) {
        if (board[i][y] == 1 || board[i][y] == 2) {
            if (board[i][y] == color) {
                for (int j = i+1; j <= x-1; j++) {
                    if (color == 1 && board[j][y] == 2) {
                        count++;
                    }

                    if (color == 2 && board[j][y] == 1) {
                        count++;
                    }
                }
            }
        }
    }
    for (int i = x+1; i <= 8; i++) {
        if (board[i][y] == 1 || board[i][y] == 2) {
            if (board[i][y] == color) {
                for (int j = x+1; j <= i-1; j++) {
                    if (color == 1 && board[j][y] == 2) {
                        count++;
                    }

                    if (color == 2 && board[j][y] == 1) {
                        count++;
                    }
                }
            }
        }
    }
    
    while(1) {
        
    }
    
}

void printBoard(vector<vector<int>> &board) {

}