#pragma once

class GameObject {
protected:
    int x, y;
    int distance;   // 한번 이동 거리
public:
    GameObject();
    GameObject(int startX, int startY, int distance_input);   // 초기 위치와 이동거리 설정

    virtual ~GameObject();   // 가상 소멸자

    virtual void move() = 0;    // 순수 가상 함수, 이동한 후 새로운 위치로 x, y 변경
    virtual char getShape() = 0; // 객체의 모양을 나타내는 문자 리턴

    int getX();
    int getY();
    void setX(int tmpX);
    void setY(int tmpY);
    bool collide(GameObject *p);
};

// ===============================Human 시작=============================
class Human: public GameObject {
private:
    char movingKey;
public:
    Human();
    Human(int startX, int startY);

    void move() override;
    char getShape() override;
    void setMovingKey(char mk);
};
// ===============================Monster 시작=============================
class Monster: public GameObject {
private:
    int movingKey;
public:
    Monster();
    Monster(int startX, int startY);

    void move() override;
    
    char getShape();
};
// ===============================Food 시작=============================
class Food: public GameObject {
private:
    int movingKey;
    int count_move = 0;
    int count_stop = 0;
public:
    Food();
    Food(int startX, int startY);

    void move() override;
    
    char getShape() override;
};