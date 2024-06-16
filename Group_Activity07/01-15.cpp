#include <iostream>

using namespace std;

class Base {
public:
	~Base() {
		cout << " Base destructor" << endl;
	}
};
class Derived : public Base {
public:
	~Derived() {
		cout << " Derived destructor" << endl;
	}
};

int main() {
	Derived d;				// destructor: Derived -> Base
	return 0;
}