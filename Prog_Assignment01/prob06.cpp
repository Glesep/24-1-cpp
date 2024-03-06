#include <iostream>
using namespace std;

int main()
{
    int N, num;
    int max = 0, min = 0;                           // 최댓값, 최솟값 정의
    cin >> N;                                       // 정수 개수

    for (int i = 0; i < N; i++)
    {
        cin >> num;

        if (i == 0)                                 // 값이 하나밖에 없으므로 최댓값, 최솟값에 둘 다 넣기
        {
            max = num;
            min = num;
        }

        if (num > max)
            max = num;

        if (num < min)
            min = num;
        
        cout << "max - min = " << max - min << endl;
    }

    return 0;
}