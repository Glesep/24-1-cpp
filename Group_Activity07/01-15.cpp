#include <iostream>

using namespace std;

class Base {
public:
	virtual ~Base() {							// 부모 클래스 소멸자는 꼭 virtual 정의
		cout << " Base destructor" << endl;
	}
};
class Derived : public Base {
public:
	~Derived() {
		cout << " Derived destructor" << endl;
	}
};

int main() {
	Derived d;				// destructor: Derived -> Base
	return 0;
}