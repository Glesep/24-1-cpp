// while 1

#include <iostream>
using namespace std;

int main()
{
    // 초기화 할 때는 무조건 따로따로 명시하자
    int sum = 0, cnt = 0;

    int variable;

    while (cnt < 10)
    {
        cin >> variable;

        if (variable % 2 == 1)
        {
            sum += variable;
            cnt++;
        }
    }

    cout << "The Sum is : " << sum << endl; // 4201215

    return 0;
}