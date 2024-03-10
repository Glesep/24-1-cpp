//code25.cpp 참고함
//뒤에서부터 밀어서 앞의 공간 쉽게 확보 가능
#include <iostream>
using namespace std;
const int MAX = 100;

int main()
{
    int n;
    cin >> n;
    int data[MAX];
    
    for (int i = 0; i < n; i++)
    {
        cin >> data[i];
    }

    int k;
    cin >> k;
    // 맨 끝에서부터 하나씩 밀기를 k번 실행
    while (k > 0)
    {
        for (int i = n-1; i >= 0; i--)
        {
            data[i+1] = data[i];
        }
        data[0] = data[n];
        k--;
    }

    for (int i = 0; i < n; i++)
        cout << data[i] << " ";
    cout << endl;

    return 0;
}