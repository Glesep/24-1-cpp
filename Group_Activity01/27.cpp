#include <iostream>
using namespace std;

int main()
{
    int MAX = 5, tmp = 0;
    int num[MAX];
    
    // 배열 값 넣기 (중요하지 않음)
    // for(int N = 0; N < MAX; N++)
    // {
    //     num[N] = N;
    // }

    tmp = num[MAX - 1];                         //맨 끝 값

    for (int N = MAX - 1; N >= 1; N--)          // 뒤에서부터 당김
    {
        num[N] = num[N-1];
    }

    num[0] = tmp;                               // 저장해놓은 맨 끝 값을 배열의 맨 앞으로 이동

    for (int N = 0; N < MAX; N++)
    {
        cout << "num[" << N << "] == " << num[N] << endl;
    }
}
