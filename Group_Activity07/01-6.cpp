#include <iostream>

using namespace std;

class Base {};
class Derived : public Base {};

int main() {
	Base* bp = new Derived;
	//Derived* dp = new Base;			// 자식 클래스 타입의 포인터로 부모 클래스 타입의 객체를 받을 수 없다.

	return 0;
};