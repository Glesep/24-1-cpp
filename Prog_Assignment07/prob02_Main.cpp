// Human의 Food 먹기 게임!!

#include "prob02_Game.h"
#include <iostream>
using namespace std;

void processManager(Game game) {
    // 세팅
    cout << "** Human wants to eat Food!! **" << endl << endl;
    game.init();
    game.printGrid();

    while(true) {
        game.humanMove();
        game.moveAll();

        if (game.isEat()) {
            cout << "Human is Winner!!" << endl;
            break;
        }

        else if (game.isFail()) {
            cout << "Fail..." << endl;
            break;
        }
        game.refreshGrid();
        game.printGrid();
    }
}

int main() {
    Game game;
    processManager(game);

    return 0;
}