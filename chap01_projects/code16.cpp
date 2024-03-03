#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// 승률 = 승리한 경기수 / 총 경기수 (실수)
int main()
{
    int T, stake, goal;
    int wins = 0;
    srand((unsigned int)time(NULL)); // pseudo-random number generator, 난수 발생기

    cout << "game trial : ";
    cin >> T;

    cout << "first money : ";
    cin >> stake;

    cout << "goal money : ";
    cin >> goal;

    for (int i = 0; i < T; i++)
    {
        int cash = stake;
        while (cash < goal && cash > 0)
        {
            if (rand() % 2 == 0) // 이기거나 지거나를 짝수, 홀수로 생각
                cash++;
            else
                cash--;
        }
        if (cash == goal)
            wins++;
    }
    cout << "Win% = " << 100 * (double)wins / T << endl;
    return 0;
}