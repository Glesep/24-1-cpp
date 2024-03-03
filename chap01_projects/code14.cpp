// 중첩 for문

#include <iostream>
using namespace std;
// y>x
int main()
{
    int cnt = 0;

    for (int x = 0; x <= 100; x++)
    {
        for (int y = 0; y <= 100; y++) // y = x에서 시작한다면 아래의 x<=y의 조건은 없어도 된다. 조건은 유연하게 사용
        {
            if (x <= y && x * x + y * y <= 10000) // && 즐겨 사용합시다
                cnt++;
        }
    }

    cout << "The Count is " << cnt << endl;
}