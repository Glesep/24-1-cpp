#include <iostream>
using namespace std;

class Base
{
public:
    Base() { cout << "Constructing base\n"; }
    virtual ~Base() { cout << "Destructing base\n"; }       // 상속을 사용할 때 base class destructor는 무조건 virtual 함수로 만들어야 한다.
                                                            // destructor는 자신의 클래스만 지우는 역할을 하기 때문에 상속받은 클래스는 관여를 하지 않는다.
};

class Derived : public Base
{
public:
    Derived() { cout << "Constructing derived\n"; }
    ~Derived() { cout << "Destructing derived\n"; }
};

int main()
{
    Derived *d = new Derived();
    Base *b = d;
    delete b;
    return 0;
}
/* 결과: 생성자 -> base ~ derived, 소멸자 derived ~ base
    Constructing base
    Constructing derived
    Destructing derived
    Destructing base
*/