// while 3

#include <iostream>
using namespace std;

int main()
{
    int tmp;
    int sum = 0, cnt = 0; // int sum, cnt = 0 은 cnt 만 0으로 초기화된 것

    do // 무조건 한번 하고 while 조건 검사
    {
        cin >> tmp;
        sum += tmp;
        cnt++;
    } while (sum > 0);

    // while(1)로도 가능

    cout << "The count is " << cnt << endl;
    return 0;
}
