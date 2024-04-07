// 중첩 for문 심화

#include <iostream>
using namespace std;

int main()
{
    int N;
    int cnt = 0;

    cin >> N;

    for (int i = 2; i <= N; i++)
    {
        for (int j = 2; j < i / 2; j++) // i는 j의 배수인데 2의 배수라도 될려면  i/2보다는 작아야 함 (배수 중 가장 작은 것이 2의 배수이므로)
        {
            if (i % j == 0)
                cnt++;
        }
    }

    // for (int a = 2; a <= N; a++)
    // {
    //     for (int b = 2; b <= N / 2; b++)
    //     {
    //         if (a != b && a % b == 0)
    //         {
    //             cnt++;
    //         }
    //     }
    // }

    cout << "The Count is " << cnt << endl;
}