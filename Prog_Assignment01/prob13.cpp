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
            // 더블로 만들어 줬어야 됐다. 그래야 범위가 제대로 잡히지
            if (y <= 2.0/3*x && y >= (1.0/3)*x && x * x + y * y <= 10000)
                cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}