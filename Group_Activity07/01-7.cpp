#include <iostream>

using namespace std;

class Base {
public:
	void show() {
		cout << "In Base";
	}
};

class Derived : public Base {
public:
	int x;
	void show() {
		cout << "In Derived";
	}
	Derived() {
		x = 10;
	}
};

int main() {
	Base* bp, b;
	Derived d;

	bp = &d;						// In Base
	bp->show();

	//cout << bp->x;				// Derived 클래스에서 정의된 x이기 때문에 Base 타입에선 읽히지 않는다.
	//return 0;

	return 0;
};