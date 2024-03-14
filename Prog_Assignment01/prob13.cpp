// 답: 1362
#include <iostream>
using namespace std;
// 2x = 3y로 접근(if문에 집어놓기)
int main()
{
    int cnt = 0;
    int x = 0, y = 0;
    for (x = 0; x <= 100; x++)                                                          // x의 범위 지정
    {   
        for (y = 0; y <= 100; y++)                                                      // y의 범위 안에서 정수 개수 세기
        {
            if (3*y <= 2*x && 3*y >= x && x * x + y * y <= 10000)
                cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}