// 답: 1362
// 나: 1366             1일 때 이상한데?
#include <iostream>
using namespace std;

int main()
{
    int cnt = 0;

    for (int x = 0; x < 100; x++)                                                        // x의 범위 지정
    {
        for (double y = ((double)1/3) * x; y <= ((double)2/3) * x; y++)                  // y의 범위 안에서 정수 개수 세기
        {
          
            if (x * x + y * y <= 10000)
                cnt++;
        }
    }

    cout << cnt << endl;

    return 0;
}