#include <iostream>
using namespace std;
const int MAX = 100;

int main()
{
    int n, num;
    int cnt = 0;                                            // cin으로 넣을거 아니면 초기화 꼼꼼히 해주기!
    cin >> n;

    int leader[MAX] = {0};                                  // cin으로 넣을거 아니면 초기화 꼼꼼히 해주기!
    
    cin >> num;
    leader[0] = num;
    cnt++;

    for (int i = 1; i < n; i++)
    {
        cin >> num;
        if (num >= leader[cnt-1])                           // leader 배열의 인덱스는 i로 다루면 안 됨
        {
            leader[cnt] = num;
            cnt++;
        }
    }

    cout << cnt << ": ";
    for (int i = 0; i < cnt; i++)
        cout << leader[i] << " ";
    cout << endl;

    return 0;
}