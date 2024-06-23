#include <iostream>

using namespace std;

class Base {
private:
	int x = 1, y = 2;
};

class Derived : public Base {
public:
	void show() {
		//cout << x << " " << y << endl;			// Base 클래스에서 x, y가 private로 설정되어 있기 때문에 자식 클래스인 Derived 클래스에서 접근 불가
	}
};

int main() {
	Derived d;
	d.show();

	return 0;
};