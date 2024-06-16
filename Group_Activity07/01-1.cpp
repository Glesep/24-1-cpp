#include <iostream>

using namespace std;

class Base {
public:
	Base() {
		cout << "Base constr called" << endl;
	}
};

class Derived : public Base {
public:
	Derived() {
		cout << "Derived constr called" << endl;
	}
};

int main() {
	Derived d;		// 상속받은 클래스의 객체 생성 시: base 클래스 생성자 -> derived 클래스 생성자

	return 0;
}