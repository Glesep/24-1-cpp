#include <iostream>
    
using namespace std;

class Box {
    int capacity;
public:
    Box() {}
    Box(double capacity) {
        this->capacity = capacity;
    }
    bool operator<(Box b) {
        return b.capacity < this->capacity ?
            true : false;
    }
};

int main()
{
    Box b1(10);
    Box b2 = Box(14);
    
    if(b1 < b2)
        cout << "B1's capacity is small" << endl;
    else
        cout << "B2's capacity is small" << endl;
    
    return 0;
}

/*
C++에서 오버로딩할 수 없는 연산자들

멤버 접근 연산자(.): 객체의 멤버에 접근할 때 사용하는 연산자입니다.
멤버 포인터 접근 연산자(.*): 멤버 포인터를 통해 클래스의 멤버에 접근할 때 사용하는 연산자입니다.
범위 해상도 연산자(::): 클래스나 네임스페이스의 멤버를 명시적으로 지정할 때 사용합니다.
조건부 연산자(?:): 세 개의 피연산자를 가지는 유일한 연산자로, 조건에 따라 두 값 중 하나를 선택합니다.
크기 결정 연산자(sizeof): 객체나 타입의 크기를 바이트 단위로 반환합니다.
정렬 지정 연산자(alignof): 객체나 타입의 정렬 요구사항을 바이트 단위로 반환합니다. (C++11 이후)
타입 ID 연산자(typeid): 객체나 타입의 type_info 객체를 반환합니다.
캐스팅 연산자들: static_cast, dynamic_cast, const_cast, reinterpret_cast와 같은 C++의 명시적 타입 캐스팅 연산자들도 오버로딩할 수 없습니다.
*/
