#include <iostream>
using namespace std;
const int MAX = 100;
int main()
{
    
    int n;
    cin >> n;
    int num[MAX];

    for (int i = 0; i < n; i++)
        cin >> num[i];

    int k;
    int min = 0, result = num[0];
    cin >> k;
    
    for (int i = 0; i < n; i++)
    {
        int len = 0;
        len = k - num[i];                                   // 거리를 구함
        if (len < 0)                                        // 절댓값화 시키기 
            len *= -1;

        if (i == 0)                                         // 초깃값 잡아주기
            min = len;
        else if (len < min)                                 // k와의 거리가 제일 짧은 정수 찾기
        {
            min = len;
            result = num[i];
        }
    }

    cout << result << endl;

    return 0;
}