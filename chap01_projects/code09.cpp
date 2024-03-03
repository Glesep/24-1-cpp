// while 2

#include <iostream>
using namespace std;

int main()
{
    int tmp;
    int sum = 0;
    // 만약 조건문으로 tmp!=-1이라면 tmp가 정의되지 않았기 때문에 무작위로 정해지므로 최초를 접근할 때 혹시라도 -1이 될 때 논리적 오류를 범할 수 있다.
    // while (tmp != -1) 으로 한 후 while 문 밖에서 한번 값을 받아 논리적 오류를 없애는 방법도 있다.
    while (1)
    {
        cin >> tmp;

        if (tmp == -1)
            break;

        if (tmp % 2 == 1) // 나머지 연산자는 나눠지는 대상이 양수일 때 실행된다.
        {
            sum += tmp;
        }
    }

    cout << "The Sum is " << sum << endl;
    return 0;
}