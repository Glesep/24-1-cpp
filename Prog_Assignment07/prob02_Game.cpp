#include <iostream>
#include <cstdlib>
#include <ctime>
#include "prob02_Game.h"

using namespace std;

Game::Game() = default;
Game::Game(int x, int y): human(x, y), monster(x, y), food(x, y) {}         // 각각의 클래스 객체들을 초기화하는 방법

void Game::setHumanMK(char mk) {
    Game::human.movingKey = mk;
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
        return false;
}

bool Game::isFail() {   // 실패 여부 확인 함수
    if (human.collide(&monster) || monster.collide(&food))
        return true;
    
    else
        return false;
}

void Game::printGrid() {    // 배열로 조지기
    for (int i = 0; i < 10; i++) {  // 행
        for (int j = 0; j < 20; j++) {  // 열
            cout << grid[i][j];
        }
        cout << endl;
    }
}

void Game::refreshGrid() {
    // 그리드 초기화
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 20; j++) {
            if (human.getX() == i  && human.getY() == j) {
                if (human.getX() == monster.getX() && human.getY() == monster.getY()) {             // human과 monster가 겹칠 때
                    grid[i][j] = monster.getShape();
                }
                else
                    grid[i][j] = human.getShape();
            }
            else if (monster.getX() == i  && monster.getY() == j) 
                grid[i][j] = monster.getShape();
            else if (food.getX() == i  && food.getY() == j)
                grid[i][j] = food.getShape();
            else
                grid[i][j] = '-';
        }
    }
}

// 게임 초기 설정
void Game::init(){
    srand((unsigned int) time(NULL));
    do {
        // 생성자 생각!!
        Human h(0,0);
        Monster m(0,0);
        Food f(0,0);

        h.setX(rand() % 10);
        h.setY(rand() % 20);

        m.setX(rand() % 10);
        m.setY(rand() % 20);

        f.setX(rand() % 10);
        f.setY(rand() % 20);

        human = h;
        monster = m;
        food = f;
    } while ((human.getX() == monster.getX() && human.getY() == monster.getY()) ||
            (human.getX() == food.getX() && human.getY() == food.getY()) ||
            (food.getX() == monster.getX() && food.getY() == monster.getY()));      // 겹치면 한 번 더 초기화

    Game::refreshGrid();
}

// 디버그용 좌표 보기
void Game::getXYAll() {
    cout << human.getX() << " " << human.getY() << " "<< human.distance << endl;
    cout << monster.getX() << " " << monster.getY() << " "<< monster.distance << endl;
    cout << food.getX() << " " << food.getY() << " "<< food.distance << endl;
}
