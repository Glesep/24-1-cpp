#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

// 안쓴듯
vector<vector<int>> move = { {0, -1}, {1, -1}, {1, 1}, {1, 0}, {0, 1} };

int main() {
    string str;
    int boardSize;
    vector<vector<string>> board;

    ifstream infile("board.txt");
    getline(infile, str);
    istringstream iss(str);
    iss >> boardSize;
    
    board.push_back(vector<string>());
    int index = 0;
    int count = 0;
    while (infile >> str) {
        board[index].push_back(str);
        if (count == boardSize-1) {
            count = 0;
            board.push_back(vector<string>());
            index++;
        }
        else
            count++;
    }
    
    
    // 위에서부터 아래로 검사하는 것이므로 아랫부분만 확인한다.
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardSize; j++) {
            int x = i;
            int y = j;
            if (board[x][y] == "1" || board[x][y] == "2") {
                int winStack = 1;
                // 하단 체크
                while (1) {
                    if (x + 1 == boardSize)
                        break;
                    if (board[x][y] != board[x+1][y])
                        break;
                    winStack++;

                    if (winStack == 5) {

                        if (board[i][j] == "1") {
                            cout << "Black" << endl;
                            return 0;
                        } 
                        
                        if (board[i][j] == "2") {
                            cout << "White" << endl;
                            return 0;
                        } 
                    }
                    x++;
                }
                x = i, y = j;
                winStack = 1;

                //좌측 하단 체크
                while (1) {
                    if (x + 1 == boardSize || y - 1 == -1)
                        break;
                    if(board[x][y] != board[x+1][y-1])
                        break;
                    winStack++;

                    if (winStack == 5) {

                        if (board[i][j] == "1") {
                            cout << "Black" << endl;
                            return 0;
                        } 
                        
                        if (board[i][j] == "2") {
                            cout << "White" << endl;
                            return 0;
                        } 
                    }
                    x++;
                    y--;
                }
                x = i; y = j;
                winStack = 1;

                // 우측 하단 체크
                while(1) {
                    if (x + 1 == boardSize || y + 1 == boardSize)
                        break;
                    if (board[x][y] != board[x+1][y+1])
                        break;
                    winStack++;

                    if (winStack == 5) {

                        if (board[i][j] == "1") {
                            cout << "Black" << endl;
                            return 0;
                        } 
                        
                        if (board[i][j] == "2") {
                            cout << "White" << endl;
                            return 0;
                        } 
                    }
                    x++;
                    y++;
                }
                x = i; y = j;
                winStack = 1;

                // 수평 검사
                while(1) {
                    if (y + 1 == boardSize)
                        break;
                    if (board[x][y] != board [x][y+1])
                        break;
                    winStack++;
                    if (winStack == 5) {

                        if (board[i][j] == "1") {
                            cout << "Black" << endl;
                            return 0;
                        } 
                        
                        if (board[i][j] == "2") {
                            cout << "White" << endl;
                            return 0;
                        } 
                    }
                    y++; 
                }
            }
        }
    }
    infile.close();
    // 승부가 안 났을 때
    cout << "Not Finished" << endl;
    return 0;
}