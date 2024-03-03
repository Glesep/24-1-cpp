// 반복문 4

#include <iostream>
using namespace std;

int main()
{
    int tmp;
    int sum = 0;

    cin >> tmp;

    while (tmp > 0)
    {
        // 자릿수 빼내기
        sum += tmp % 10;
        tmp /= 10; // tmp = tmp / 10;
    }

    cout << "The Sum is " << sum << endl;
}