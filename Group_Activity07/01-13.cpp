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
	A* a = new B();				// 원래 문제에는 초기화를 시키지 않았음
	a->func();					// In class B, func의 Overriding
	return 0;
}