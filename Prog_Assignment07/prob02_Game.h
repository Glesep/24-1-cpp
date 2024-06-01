#pragma once
// h는 h를 include
#include "prob02_GameObject.h"

class Game {
private:
    Human human; 
    Monster monster; 
    Food food;
    char grid[10][20];
public:
    Game();
    Game(Human h, Monster m, Food f);

    void humanMove();
    void moveAll();     // 모든 요소 움직이게 하는 함수
    bool isEat();   // 성공, 실패 확인 함수
    bool isFail();
    void printGrid();   // 격자판 그리는 함수
    void init();
    
};