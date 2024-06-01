// Human의 Food 먹기 게임!!

#include "prob02_Game.cpp"

void processManager(Game game) {
    // 세팅
    game.init();

    cout << "** Human의 Food 먹기 게임을 시작합니다. **" << endl << endl;

    while(true) {
        game.printGrid();
        game.humanMove();
        game.moveAll();
    }
}