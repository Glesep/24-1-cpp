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
    void checkStone(int &x, int &y, int &color) {
        if (color == 1) {
            vector<int> tmp = {x, y};
            black.push_back(tmp);
        }
        else if (color == 2) {
            vector<int> tmp = {x, y};
            white.push_back(tmp);
        }
    }

    bool checkHr(vector<vector<int>> &colorStone) {
        
        for (int i = 0; i < colorStone.size(); i++) {
                // y좌표가 같고, x좌표가 1씩 늘어날 때,
            if (colorStone[i][1] == colorStone[i+1][1] && colorStone[i][1] == colorStone[i+2][1] && colorStone[i][1] == colorStone[i+3][1] && colorStone[i][1] == colorStone[i+4][1] &&
                colorStone[i][0] == colorStone[i+1][0]+1 && colorStone[i][0] == colorStone[i+2][0]+2 && colorStone[i][0] == colorStone[i+3][0]+3 && colorStone[i][0] == colorStone[i+4][0]+4)
                return true;  
        }
    }
    
    bool checkVt(vector<vector<int>> &colorStone) {
        int stack = 1;
        vector<int> lookStone;
        // 주시하고 있는 바둑돌과 비교하는 바둑돌이 조건 일치한다면 주시하고 있는 바둑돌 변경
        // stack이 5가 되면 true 리턴
        //while로 연달아 나오는 거 표현
        for (int i = 0; i < colorStone.size(); i++) {
            lookStone = colorStone[i];
            bool connect = true;     
            while (connect) {
                int index = 0;
                if (lookStone[0] == colorStone[index][0] && lookStone[1]+1 == colorStone[index][1]) {
                    lookStone = colorStone[index];
                    stack++;
                    index++;
                }
                else {
                    stack = 1;
                    connect = false;
                }
                
            }
        }
    }
    
};

int main() {
    int boardSizeInt = 0;
    string boardSizeStr, place;
    Stone stone;

    ifstream infile("board.txt");
    getline(infile, boardSizeStr);
    boardSizeInt = stoi(boardSizeStr);
    
    int x = 1, y = 1;
    while (infile >> place) {
         
        int placeInt = stoi(place);
        if (placeInt == 1 || placeInt == 2) {
            stone.checkStone(x, y, placeInt);
        }
        
        // x좌표가 size와 같아졌을 때,
        if (x == boardSizeInt) {
            x = 1;
            y++;
        }
        else
            x++;
    }

    infile.close();

    for (int i = 0; i < stone.white.size(); i++) {
        for (int j = 0; j < 2; j++) {
            cout << stone.white[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}