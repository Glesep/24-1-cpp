#include <iostream>

using namespace std;

class A {
	double d;
public:
	virtual void func() {
		cout << "In class A\n";
	}
};
class B : public A {
	int a = 15;
public:
	void func() {
		cout << "In class B\n";
	}
};
int main() {
	A* a = new A();
	B b;
	a = &b;					// A 타입 이름 없는 객체에 대한 Garbage 생성됨
	a->func();				// In class B, Overriding
	return 0;
}