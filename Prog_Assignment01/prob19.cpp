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
    cin >> k;
    // 초기값 잘 잡기
    int min = k-num[0], result = num[0];
    
    for (int i = 1; i < n; i++)
    {
        int len = k - num[i];  
                                        
        if (len < 0)                                        // 절댓값화 시키기 
            len *= -1;

        if (len < min)                                 // k와의 거리가 제일 짧은 정수 찾기
        {
            min = len;
            result = num[i];
        }
    }

    cout << result << endl;

    return 0;
}