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
	B b;
	b.func();						// In class B
	return 0;
}