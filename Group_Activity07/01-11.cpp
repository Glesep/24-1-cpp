#include <iostream>

using namespace std;

class A {
	float d;
public:
	int a;
	void change(int i) {
		a = i;
	}
	void value_a() {
		cout << a << endl;
	}
};
class B : public A {
	int a = 15;
public:
	void print() {
		cout << a << endl;
	}
};

int main() {
	B b;
	b.change(10);				// 클래스 A의 a에 10 대입 (change 메소드는 A 클래스의 멤버이므로)
	b.print();					// 15
	b.value_a();				// 10
	return 0;
}