#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Term {
public: 
    int coef;
    int expo;

    Term() = default;
    Term(int cf, int ep): coef(cf), expo(ep) {}
};

int main() {

    // 동적 배열을 생성하면 new는 배열의 주소가 아니라 배열의 첫 번째 주소를 반환한다.
    //따라서 포인터의 타입이 int *, string *, Term *이다.

    int *pia = new int [10];                    // 길이가 10인 int타입 배열의 동적 생성
    string *psa = new string [10];              // 길이가 10인 string타입 배열의 동적 생성
    Term *pta = new Term [10];                  // 길이가 10인 Term타입 배열의 동적 생성

    //배열의 첫 번째 원소의 주소를 마치 배열의 이름처럼 사용할 수 있다. 
    pia[0] = 10;
    pia[1] = 20;
    pia[2] = 30;

    for (int i = 0; i < 3; i++)
        cout << pia[i] << endl;

    //동적 생성된 배열을 삭제하는 연산자는 delete []
    delete [] pia;
    delete [] psa;
    delete [] pta;

    return 0;
}