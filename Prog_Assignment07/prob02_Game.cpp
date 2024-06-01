#include <iostream>
#include <cstdlib>
#include <ctime>
#include "prob02_Game.h"

using namespace std;

Game::Game() = default;
Game::Game(Human h, Monster m, Food f): human(h), monster(m), food(f) {}

void Game::humanMove() {
    cout << "왼쪽(a), 아래(s), 위(d), 오른쪽(f) ";
    char mk;
    cin >> mk;
    human.setMovingKey(mk);
}

void Game::moveAll() {  // 모든 요소 움직이게 하는 함수
    human.move();
    monster.move();
    food.move();
}    
bool Game::isEat() {    // 먹었는가 확인하는 함수
    // 1. human - food : 성공
    if(human.collide(&food))        // 다형성 사용
        return true;
    
    else
        false;
}

bool Game::isFail() {   // 실패 여부 확인 함수
    if (human.collide(&monster) || monster.collide(&food))
        return true;
    
    else
        false;
}

void Game::printGrid() {    // 배열로 조지기
    for (int i = 0; i < 10; i++) {  // 행
        for (int j = 0; j < 20; j++) {  // 열
            cout << grid[i][j];
        }
        cout << endl;
    }
}

void Game::init(){
    srand((unsigned int) time(NULL));
    do {
        human.setX(rand() % 20);
        human.setY(rand() % 10);

        monster.setX(rand() % 20);
        monster.setY(rand() % 10);

        food.setX(rand() % 20);
        food.setY(rand() % 10);
    } while ((human.getX() == monster.getX() && human.getY() == monster.getY()) ||
            (human.getX() == food.getX() && human.getY() == food.getY()) ||
            (food.getX() == monster.getX() && food.getY() == monster.getY()));      // 겹치면 한 번 더 초기화

    // 그리드 초기화
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) {
            if (human.getX() == i  && human.getY() == j)
                grid[i][j] = human.getShape();
            else if (monster.getX() == i  && monster.getY() == j)
                grid[i][j] = monster.getShape();
            else if (food.getX() == i  && food.getY() == j)
                grid[i][j] = food.getShape();
            else
                cout << '-';
        }
    }
}