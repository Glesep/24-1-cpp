#include <iostream>
using namespace std;

int main() {

    double i = 42.0;
    double &r = i;                  // &은 선언의 일부이다. r은 참조이다.
    double *p;                      // *은 선언의 일부이다. p는 포인터이다.
    p = &i;                         // &은 주소 추출 연산자이다.
    *p = i;                         // *은 간접참조 연산자이다. (포인터 내의 값)
    double &r2 = *p;                // &는 선언의 일부이다. r2는 참조이다. / *는 간접참조 연산자이다.

    // 간접참조 연산자 : 포인터가 가리키는 객체를 사용하게 한다.
    // 포인터가 클래스의 객체를 가리키는 경우 (*pr).variable 대신 pr->variable의 표현을 쓸 수 있다.


    // Tip: 포인터는 반드시 초기화하라
    // 포인터에 어떤 주소도 쓰지 않은 경우 NULL pointer로 초기화하라.
    int *p1 = nullptr;  // c++
    int *p2 = 0;        // 직접 상수 0으로 초기화, nullptr은 주소를 0으로 초기화시킨다 생각
    int *p3 = NULL;     // C style, <cstdlib> include시


    // NULL pointer에 대한 간접참조는 오류
    int *p4 = nullptr;
    int x = *p4;        // error
    if (p4 != nullptr)
        x = *p4;

    // 조건문에서 nullptr은 false, 아니면 true
    double *p5 = nullptr;
    if (p5) {}              // false

    double val = 40.2;
    double *p6 = &val;
    if (p6) { }             // true


    return 0;
}