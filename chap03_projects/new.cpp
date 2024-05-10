#include <iostream>
using namespace std;

class Term {
public: 
    int coef;
    int expo;

    Term() = default;
    Term(int cf, int ep): coef(cf), expo(ep) {}
};

// new는 이름없는 객체를 생성하고 해당 객체의 주소를 반환한다.
int main() {

    int p;                  // 이름이 지정된 int 객체
    int *pi = new int;      // 이름이 없는 int 객체를 만들고 그 주소를 반환하는 new
    int *pi2 = new int(3);  // 3으로 초기화된 이름 없는 int 객체


    Term t(2,3);
    Term s = t;

    Term *pterm = new Term(3,4);            // 이름이 없는 Term 타입의 객체의 동적 생성
    Term *q = pterm;

    *pi = 10;
    pterm->coef = 2;

    cout << *pi << endl;
    cout << pterm->coef << endl;

    return 0;
}