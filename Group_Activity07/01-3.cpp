#include <iostream>

using namespace std;

class P {
public:
	void print() {
		cout << "Inside P" << endl;
	}
};

class Q : public P {
public:
	void print() {
		cout << "Inside Q" << endl;
	}
};

class R: public Q { };

int main() {
	R r;
	r.print();					// Inside Q, P의 print 함수는 Q 클래스에서 메소드 숨김 처리가 되었기 때문에, Q의 print함수가 실행된다.

	P* pptr = &r;
	pptr->print();				// Inside P, pptr의 타입은 P이기 때문에 P의 print 메소드를 출력한다.

	return 0;
};