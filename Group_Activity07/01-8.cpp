#include <iostream>

using namespace std;

class Base {
public:
	void fun() {
		cout << "Base::fun() called";
	}
	void fun(int i) {
		cout << "Base::fun(int i) called";
	}
};

class Derived : public Base {
public:
	void fun() {
		cout << "Derived::fun() called";
	}
};

int main() {
	Derived d;
	d.fun();								// 메소드 숨김 현상이 오버로딩된 두 fun() 함수에 다 적용
	// d.fun(5);							// 따라서 실행 불가
	return 0;
}