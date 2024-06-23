#include <iostream>

using namespace std;

class Base {
public:
	virtual string print() const {
		return "This is Base class";
	}
};
class Derived : public Base {
public:
	virtual string print() const {
		return "This is Derived class";
	}
};

void describe(Base p) {
	cout << p.print() << endl;
}

int main() {
	Base b;
	Derived d;
	describe(b);					// This is Base class
	describe(d);					// This is Base class, Base p는 포인터 형식이 아님. Base 타입 변수에 Derived 객체를 넣으면 소수점 잘리듯이 Derived 내용은 저장 안됨
	return 0;
}