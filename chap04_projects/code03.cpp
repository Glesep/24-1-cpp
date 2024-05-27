#include <iostream>
    
using namespace std;

class Base {
    int baseMem;
public:
    Base() {
        cout << "Constructing base\n";
    }
};

class Derived: public Base {
    int deriveMem;
public:
    Derived() {
        cout << "Construncting derived\n";
    }
};

int main()
{
    Derived d;              // 파생클래스의 생성자는 먼저 베이스클래스의 생성자를 호출하여 베이스클래스의 멤버들을 생성하고, 이어서 자신의 추가 멤버들을 생성한다.
    
    return 0;
}
