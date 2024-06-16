#include <iostream>

using namespace std;

class Base {
public:
	int x, y;
	Base(int a, int b) {
		x = a; y = b;
	}
};
class Derived : public Base {
public:
	Derived(int p, int q) : Base(p, q) {}					// Base클래스의 변수 초기화이기 때문에 Base 생성자를 명시해야 된다.
	//Derived(int p, int q) : x(p), y(q) {}
	void print() {
		cout << x << " " << y;
	}
};

int main(void) {
	Derived q(10, 10);
	q.print();
	return 0;
}