#include <iostream>

using namespace std;

class Base {
protected:
	int x, y;
public:
	Base(int a = 1, int b = 2) : x(a), y(b) { }				// default 생성자 - 매개변수에 아무것도 넣지 않는 것 ( 기본적으로 a = 1 , b = 2 )
};															// 위의 함수에 매개변수를 넣으면 넣는대로의 동작을 함

class Derived : public Base {
public:
	void show() {
		cout << x << " " << y;					// x, y는 Base 클래스에서 protected로 설정되었기 때문에 자식클래스에서 접근 가능
	}
};

int main() {
	Derived d;
	d.show();

	return 0;
};