// '/' 연산을 할 때 변수끼리의 타입을 생각하자!!

#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    int v, sum = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> v;
        sum += v;
    }

    cout << "The average is " << (double)sum / N << endl; // type casting, ?씠 以꾩뿉?꽌留? ?떎?닔濡? 蹂??솚

    return 0;
}
