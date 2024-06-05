// Human의 Food 먹기 게임!!
// 가상함수는 정의하는 것 잊지 말기
#include <iostream>
#include <cstdlib>
#include <ctime>
#include "prob02_GameObject.h"
using namespace std;

GameObject::GameObject() = default;
// 생성자를 초기화할 때는 헤더에 설정된 순서대로, 들어가는 변수와 넣는 변수 명이 같지 않도록 주의!
GameObject::GameObject(int startX, int startY, int distance_input = 1): x(startX), y(startY), distance(distance_input) {}   // 초기 위치와 이동거리 설정

GameObject::~GameObject() {}    // 가상 소멸자

int GameObject::getX() { return x; }
int GameObject::getY() { return y; }

void GameObject::setX(int tmpX) { x = tmpX; }
void GameObject::setY(int tmpY) { y = tmpY; }

bool GameObject::collide(GameObject *p) {   // 이 객체가 객체 p와 충돌했으면 true 리턴
    if(this->x == p->getX() && this->y == p->getY())
        return true;
    else
        return false;
}

// ===============================Human 시작===================================
Human::Human() = default;
Human::Human(int startX, int startY): GameObject(startX, startY) {}

// 이거 다른곳으로 옮기기
void Human::move() {
    // Human의 움직임
    if (movingKey == 'a' && y > 0)       { y -= distance; }
    else if (movingKey == 's' && x < 9)  { x += distance; }
    else if (movingKey == 'd' && x > 0)  { x -= distance; }
    else if (movingKey == 'f' && y < 19)  { y += distance; }
}
    
char Human::getShape() {
    return 'H';
}


// ===============================Monster 시작=============================
Monster::Monster() = default;
Monster::Monster(int startX, int startY): GameObject(startX, startY, 2) {}

void Monster::move() {
    srand((unsigned int) time(NULL));
    movingKey = rand() % 4 + 1;         // 1 ~ 4 난수
    if (movingKey == 1 && y > 1)       { y -= distance; }
    else if (movingKey == 2 && x < 8)  { x += distance; }
    else if (movingKey == 3 && x > 1)  { x -= distance; }
    else if (movingKey == 4 && y < 18)  { y += distance; }
}

char Monster::getShape() {
    return 'M';
}

// ===============================Food 시작===============================
Food::Food() = default;
Food::Food(int startX, int startY): GameObject(startX, startY) {}
void Food::move() {
    srand((unsigned int) time(NULL));
    int move = rand() % 2;  // 0, 1 랜덤
    // move 2, stop 3
    if ((!move && count_stop < 3) || count_move == 2) {       // 3번까지 안 움직임
        count_stop++;
    }
    else if (count_stop == 3 || (move && count_move < 2)) {                  // 3번 안 움직였거나 move == 1일 때, 움직임
        movingKey = rand() % 4 + 1;         // 1 ~ 4 난수
        if (movingKey == 1 && y > 0)       { y -= distance; }
        else if (movingKey == 2 && x < 9)  { x += distance; }
        else if (movingKey == 3 && x > 0)  { x -= distance; }
        else if (movingKey == 4 && y < 19)  { y += distance; }
        
        count_move++;
        if (count_move + count_stop == 5) {
            count_move = 0;
            count_stop = 0;
        }
    }
}

char Food::getShape() {
    return '@';
}