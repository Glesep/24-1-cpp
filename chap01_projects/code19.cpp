#include <iostream>
#include <string>                                           // string 문자열 사용 위함
using namespace std;
const int MAX = 100;

int main()
{
    string words[MAX];                                      // 최대 100개의 문자열을 저장할 수 있는 배열 선언

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> words[i];

    string str1, str2;
    cin >> str1 >> str2;

    for (int i = 0 ; i < n; i++)
    {
        if (words[i] >= str1 && words[i] <= str2)           // 사전식 순서로 "크다 : 더 뒤에 나온다", "작다 : 더 앞에 나온다"
        {
            cout << words[i] << endl;
        }
    }

}