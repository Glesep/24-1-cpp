#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>

using namespace std;
int countStoneToCapture(int x, int y, int color);

vector<vector<int>> mover { {-1, 0}, {-1, 1}, {0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1} };      // 시계 방향

class OthelloGame {
public:
    vector<vector<int>> board;

    // 돌 찾기
    int countStoneToCapture(int x, int y, int color) {
        int now_x;
        int now_y;
        int captureStone = 0;
        // 방향마다 체크하는 
        for (int dir = 0; dir < mover.size(); dir++) {
            int count_tmp = 0;
            now_x = x;
            now_y = y;
            while(now_x >= 0 && now_x < 8 && now_y >= 0 && now_y < 8) {
                now_x += mover[dir][0];
                now_y += mover[dir][1];
                // 범위 거르기
                if (now_x == -1 || now_x == 8 || now_y == -1 || now_y == 8)
                    break;

                if (color == 1) {   
                    if (board[now_x][now_y] == 0) {
                        break;
                    }
                    // 2(흰색일 때)
                    else if (color != board[now_x][now_y]) {
                        count_tmp++;
                        continue;
                    }
                    else if (color == board[now_x][now_y]) {
                        captureStone += count_tmp;
                        break;
                    }
                }
                if (color == 2) {   
                    if (board[now_x][now_y] == 0) {
                        break;
                    }
                    // 1(흰색일 때)
                    else if (color != board[now_x][now_y]) {
                        count_tmp++;
                        continue;
                    }
                    else if (color == board[now_x][now_y]) {
                        captureStone += count_tmp;
                        break;
                    }
                }
            }
        }
        return captureStone;
    } 
    // 보드 현황 출력
    void printBoard() {
        for (auto i : board) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
    }

    void adjInput(int &put_x, int &put_y, int &color) {
        
        int now_x = put_x;
        int now_y = put_y;
        
        board[now_x][now_y] = color;

        bool was_enmColor = false;
        bool was_myColor = false;
        
        for (int dir = 0; dir < mover.size(); dir++) {
            vector<vector<int>> swapStone;
            now_x = put_x;
            now_y = put_y;
            int end_x, end_y;
            while (now_x >= 0 && now_x < 8 && now_y >= 0 && now_y < 8) {
                
                now_x += mover[dir][0];
                now_y += mover[dir][1];

                // 벗어난 범위 거르기
                if (now_x == -1 || now_x == 8 || now_y == -1 || now_y == 8)
                    break;
                
                // 빈 칸이라면
                if (board[now_x][now_y] == 0) {
                    break;
                }
                // 2(흰색일 때)
                else if (board[now_x][now_y] != color) {
                    vector<int> tmp = {now_x, now_y};
                    swapStone.push_back(tmp);
                    was_enmColor = true;
                    continue;
                }
                // 똑같은 색일 때
                else if (board[now_x][now_y] == color) {
                    // 먼저 적 돌을 확인 한 적 있을 때 
                    if(was_enmColor == true) {
                        was_myColor = true;
                        if (was_myColor && was_enmColor) {
                            for (int i = 0; i < swapStone.size(); i++) {
                                int x_tmp = swapStone[i][0];
                                int y_tmp = swapStone[i][1];
                                if (color == 1)
                                    board[x_tmp][y_tmp] = 1;
                                else if (color == 2) 
                                    board[x_tmp][y_tmp] = 2;
                            }
                        }
                    }
                    break;
                }
            }
        }
        // 턴 따라 바꿔주기
        if (color == 1)
            color = 2;
        else if (color == 2)
            color = 1;
    }
    // 결과 판정 함수
    bool whoWin() {
        bool zero = false, black = false, white = false;
        int count_B = 0, count_W = 0;

        // 보드에 무슨 돌이 있는가 판정, 결과에 영향을 미침
        for (auto i : board) {
            for (auto j : i) {
                if (j == 0) {
                    zero = true;
                }
                if (j == 1) {
                    black = true;
                    count_B++;
                }
                if (j == 2) {
                    white = true;
                    count_W++;
                }
            }
        }

        // 보드에 한 종류의 돌밖에 없을 때
        if (zero == true && ((black == true && white == false) || (black == false && white == true))) {
            if (black == true)
                cout << "Player win!!" << endl;
            else if (white == true)
                cout << "Computer win!!" << endl;
            return true; 
        }

        // 보드에 돌이 꽉 찼을 때
        if (zero == false && black == true && white == true) {
            if (count_B > count_W)
                cout << "Player win!!" << endl;
            else if (count_B < count_W)
                cout << "Computer win!!" << endl;
            else
                cout << "Draw" << endl;
            return true;
        }
        return false;
    }
};

int main() {
    OthelloGame OG;
    // 바둑돌 세팅
    vector<int> tmp(8, 0);
    for (int i = 0; i < 8; i++) {
        OG.board.push_back(tmp);
    }

    //초기 돌 배치
    OG.board[3][3] = 1, OG.board[4][4] = 1;
    OG.board[3][4] = 2, OG.board[4][3] = 2;

    OG.printBoard();

    int put_x, put_y;
    // 무조건 사람 먼저 시작
    int turnColor = 1;
    while(1) {
        cout << "Your turn: ";
        // 힌트 알려주기 위한 좌표 출력 과정
        int maxCapture_H = 0;
        for (int i = 0; i < OG.board.size(); i++) {
            for (int j = 0; j < OG.board.size(); j++) {
                if (OG.board[i][j] == 0) {
                    int tmp = OG.countStoneToCapture(i, j, turnColor);
                    // 최댓값 갱신 
                    if (tmp > maxCapture_H)
                        maxCapture_H = tmp;
                }
            }
        }
        vector<vector<int>> maxCaptures_H;
        for (int i = 0; i < OG.board.size(); i++) {
            for (int j = 0; j < OG.board.size(); j++) {
                if (OG.board[i][j] == 0) {
                    int tmp = OG.countStoneToCapture(i, j, turnColor);
                    // 바뀌는 돌의 개수가 최댓값인 위치 파악 
                    if (tmp == maxCapture_H) {
                        vector<int> tmp_vec = {i, j};
                        maxCaptures_H.push_back(tmp_vec);
                    }
                }
            }
        }
        cout << "(Hint: ";
        for (int i = 0 ; i < maxCaptures_H.size(); i++) {
            cout << "(";
            for (int j = 0; j < maxCaptures_H[i].size(); j++) {
                if (j != 0)
                    cout << ", ";
                cout << maxCaptures_H[i][j];
            }
            cout << ")";
            if (i != maxCaptures_H.size()-1)
                cout << ", ";
        }
        cout << ")" << endl;

        cin >> put_x >> put_y;

        // 사람이 이미 돌이 있는 곳에 놓으려 했을 경우
        if (OG.board[put_x][put_y] != 0) {
            cout << "Wrong Way!" << endl;
            continue;
        }
            
        OG.adjInput(put_x, put_y, turnColor);

        cout << endl;
        OG.printBoard();
        // 결과 판정 과정 (게임을 끝낼지 확인)
        bool result = false;
        result = OG.whoWin();
        if (result)
            break;

        cout << "Com's turn: ";
        int maxCapture_C = 0;
        // 어디가 돌을 많이 뒤집는지 확인
        for (int i = 0; i < OG.board.size(); i++) {
            for (int j = 0; j < OG.board.size(); j++) {
                if (OG.board[i][j] == 0) {
                    int tmp = OG.countStoneToCapture(i, j, turnColor);
                    // 뒤집는 돌의 수의 최댓값 갱신 
                    if (tmp > maxCapture_C)
                        maxCapture_C = tmp;
                }
            }
        }

        vector<vector<int>> maxCaptures_C;
        for (int i = 0; i < OG.board.size(); i++) {
            for (int j = 0; j < OG.board.size(); j++) {
                if (OG.board[i][j] == 0) {
                    int tmp = OG.countStoneToCapture(i, j, turnColor);
                    // 뒤집는 돌의 개수가 최댓값인 위치 파악 
                    if (tmp == maxCapture_C) {
                        vector<int> tmp_vec = {i, j};
                        maxCaptures_C.push_back(tmp_vec);
                    }
                }
            }
        }

        // 한 곳밖에 없을 경우 그냥 적용
        if (maxCaptures_C.size() == 1) {
            cout << maxCaptures_C[0][0] << " " << maxCaptures_C[0][1] << endl << endl;
            OG.adjInput(maxCaptures_C[0][0], maxCaptures_C[0][1], turnColor);
        }
        
        // 여러 곳 있을 경우 랜덤하게 고르기
        else {
            // 현재 시간을 seed로 설정
            srand((unsigned int) time(NULL));
            int random = (rand() % (maxCaptures_C.size()));
            cout << maxCaptures_C[random][0] << " " << maxCaptures_C[random][1] << endl << endl;
            OG.adjInput(maxCaptures_C[random][0], maxCaptures_C[random][1], turnColor);

        }
        OG.printBoard();
        // 결과 판정 과정 (게임을 끝낼지 확인)
        result = OG.whoWin();
        if (result)
            break;
    }

    return 0;
}



