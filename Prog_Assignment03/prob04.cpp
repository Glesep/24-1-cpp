#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

// 바둑돌 색, 위치만 저장하자
// 같은 색 기준으로 위치 비교해서 5개 된 색을 찾자

class Stone {
public:
    vector<vector<int>> white;
    vector<vector<int>> black;

    // x, y는 바둑판의 좌표
    void checkStone(int x, int y, int color) {
        if (color == 1) {
            vector<int> tmp {x, y};
            black.push_back(tmp);
        }
        else if (color == 2) {
            vector<int> tmp {x, y};
            white.push_back(tmp);
        }
    }

    void whoWin() {

    }
};

int main() {
    int boardSizeInt = 0;
    string boardSizeStr, place;
    Stone stone;

    ifstream infile("board.txt");
    getline(infile, boardSizeStr);
    boardSizeInt = stoi(boardSizeStr);
    
    int x = 0, y = 0;
    while (infile >> place) {
        int placeInt = stoi(place);
        if (placeInt == 1 || placeInt == 2) {
            stone.checkStone(x, y, placeInt);
        }
        // x좌표가 size와 같아졌을 때,
        if (x == boardSizeInt) {
            x = 0;
            y++;
        }
        x++;
    }

    infile.close();

    for (int i = 0; i < stone.black.size(); i++) {
        for (int j = 0; j < 2; j++) {
            stone.black[i][j];
        }
    }

    return 0;
}