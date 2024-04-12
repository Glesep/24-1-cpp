#include <iostream>
#include <vector>
using namespace std;
// 이동했던 좌표들은 벡터에 저장한다.

class AvoidingWalk {
public:
    int whereWeGo;
    int howLong;
    vector<int> placeNow;
    vector<vector<int>> moved;

    void traceChecker() {
        int placeX = placeNow[0], placeY = placeNow[1];

        // y가 증가할 때
        if (whereWeGo == 0) {
            // 기존 흔적 체크(한번 이동할때마다 체크한다 생각)
            for (int i = 0; i < howLong; i++) {
                for (auto it = moved.begin(); it < moved.end(); it++) {
                    if ((*it)[0] == placeX && (*it)[1] == placeY+1) {
                        cout << "invalid move" << endl;
                        return;
                    }   
                }
                placeY++; 
            }
            
            // 없다면 placeNow에 반영
            for (int i = 0; i < howLong; i++) {
                placeNow[1]++;
                moved.push_back(vector<int> {placeNow[0], placeNow[1]});
            }
            cout << placeNow[0] << " " << placeNow[1] << endl;
        }

        // x가 증가할 때
        if (whereWeGo == 1) {
            for (int i = 0; i < howLong; i++) {
                for (auto it = moved.begin(); it < moved.end(); it++) {
                    if ((*it)[0] == placeX+1 && (*it)[1] == placeY+1) {
                        cout << "invalid move" << endl;
                        return;
                    }    
                }
                placeX++;
            }

            for (int i = 0; i < howLong; i++) {
                placeNow[0]++;
                moved.push_back(vector<int> {placeNow[0], placeNow[1]});
            }
            cout << placeNow[0] << " " << placeNow[1] << endl;
        }

        // y가 감소할 때
        if (whereWeGo == 2) {
            for (int i = 0; i < howLong; i++) {
                for (auto it = moved.begin(); it < moved.end(); it++) {
                    if ((*it)[0] == placeX && (*it)[1] == placeY-1) {
                        cout << "invalid move" << endl;
                        return;
                    }   
                }
                placeY--; 
            }

            for (int i = 0; i < howLong; i++) {
                placeNow[1]--;
                moved.push_back(vector<int> {placeNow[0], placeNow[1]});
            }
            cout << placeNow[0] << " " << placeNow[1] << endl;
        }

        // x가 감소할 때
        if (whereWeGo == 3) {
            for (int i = 0; i < howLong; i++) {
                for (auto it = moved.begin(); it < moved.end(); it++) {
                    if ((*it)[0] == placeX-1 && (*it)[1] == placeY) {
                        cout << "invalid move" << endl;
                        return;
                    }    
                }
                placeX--;
            }
            for (int i = 0; i < howLong; i++) {
                placeNow[0]--;
                moved.push_back(vector<int> {placeNow[0], placeNow[1]});
            }
            cout << placeNow[0] << " " << placeNow[1] << endl;
        }
    }
};


int main() {
    AvoidingWalk AW;
    
    // 현재 좌표
    AW.placeNow = {0, 0};
    // (0,0) 좌표도 기록 해주기
    AW.moved.push_back(vector<int>{0, 0});
    

    while(1) {
        cin >> AW.whereWeGo;
       
        cin >> AW.howLong;

        if (AW.whereWeGo == -1 && AW.howLong == -1) 
            break;

        AW.traceChecker();
    }


    return 0;
}



