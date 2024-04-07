// '/' 연산을 할 때 변수끼리의 타입을 생각하자!!

#include <iostream>
#include <cmath> //수학 함수

using namespace std;

// const: 상수 == 값이 고정됨, 코드상에서 수정 불가능
const int MIN = 0;
const int MAX = 360;
const int STEP = 10;

int main()
{
    double radian, pi, value;
    pi = 4.0 * atan(1.0); // tan(pi/4) = 1.0, atan 값은 double 형식

    cout << "Angle : SIN" << endl;

    for (int degree = MIN; degree <= MAX; degree += STEP)
    {
        radian = pi * ((double)degree / 180); // 정수끼리 '/' 연산을 하면 몫을 반환
        value = sin(radian);
        cout << degree << " : " << value << endl;
    }

    return 0;
}