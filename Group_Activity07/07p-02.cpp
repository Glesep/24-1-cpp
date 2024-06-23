#include <iostream>

using namespace std;

class Base {
public:
    // Base() {
    //     cout << "Base constructor" << endl;
    // }
    virtual ~Base() {
        cout << "Base destructor" << endl;
    }
};

class Derived: public Base {
public:
    // Derived() {
    //     cout << "Derived constructor" << endl;
    // }
    ~Derived() {
        cout << " Derived destructor" << endl;
    }
};

int main()
{
    Derived d;      // Base constructor -> Derived constructor 순으로 생성자 생성
                    // Derived destructor -> Base destructor 순으로 소멸자 생성
    
    return 0;
}
