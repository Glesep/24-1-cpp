// Human의 Food 먹기 게임!!

// 현재 움직이는 기능은 구현
// 먹어서 끝나는 것 까지 구현
#include "prob02_Game.h"
#include <iostream>
using namespace std;

void processManager(Game game) {
    // 세팅
    cout << "** Human wants to eat Food!! **" << endl << endl;
    game.getXYAll(); // 디버그

    game.init();

    game.getXYAll(); // 디버그
    game.printGrid();

    while(true) {
        // 사람의 움직임에 대한 키 받기
        cout << "Left(a), Down(s), Up(d), Right(f), exit(e) : ";
        char mk;
        cin >> mk;

        if (mk == 'e') {
            cout << "Exit game..." << endl;
            break;
        }

        else if (!(mk == 'a' || mk == 's' || mk == 'd' || mk == 'f')) {
            cout << "Wrong Key!" << endl;
            continue;
        }
             
        game.setHumanMK(mk);
        game.moveAll();
        game.getXYAll();

        game.refreshGrid();
        game.printGrid();

        if (game.isEat()) {
            cout << "Human is Winner!!" << endl;
            break;
        }

        else if (game.isFail()) {
            cout << "Fail..." << endl;
            break;
        }
    }
}

int main() {
    Game game(0,0);         // 각 객체들의 x,y를 0으로 초기화, distance 클래스 따라 설정
    processManager(game);   

    return 0;
}