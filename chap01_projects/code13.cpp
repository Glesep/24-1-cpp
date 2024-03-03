// 중첩 for문

#include <iostream>
using namespace std;

int main()
{
    int cnt = 0;
    for (int x = 0; x <= 100; x++)
    {
        for (int y = 0; y <= 100; y++)
        {
            if (x * x + y * y <= 10000)
                cnt++;
        }
    }

    cout << "The Count is " << cnt << endl;
}