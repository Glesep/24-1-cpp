#include <iostream>
using namespace std;

class Base {
	int arr[10];				// private 속성, 크기는 int 변수 10개이니 40bytes
};

class Derived : public Base {
	int d;						// private 속성, 크기는 int 변수 1개이니 4bytes
};

int main() {
	cout << sizeof(Derived);	// 40bytes + 4bytes == 44bytes

	return 0;
}