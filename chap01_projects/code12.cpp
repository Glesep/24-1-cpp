#include <iostream>
using namespace std;

int main()
{
    int N;
    int two = 1;

    cin >> N;

    while (N > two)
    {
        two *= 2;

        if (N < two)
        {
            two /= 2;
            break;
        }
    }

    // while (N * 2 < = N)                                          곱한 것이 N보다 작거나 같을때를 기준으로 하면 코드가 훨씬 짧아짐
    //  p *= 2;

    cout << "Two is " << two << endl;
}