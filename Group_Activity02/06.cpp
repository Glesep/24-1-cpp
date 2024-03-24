#include <iostream>
#include <string>
using namespace std;

char mostFrequentChar(string str)
{
    int n = str.length();
    int count[n] = {0};                             // 단어의 빈도수 계산
    for (int i = 0; i < n; i++)
    {
        int index = 0;
        while(1)
        {
            // 찾아질 때마다 해당 인덱스의 빈도수 증가
            if (str.find(str[i], index) != string::npos)
            {
                count[i]++;
                index = str.find(str[i], index) + 1;
            }
            // 더 이상 없을 때 종료
            else if (str.find(str[i], index) == string::npos)
                break;
        }
    }
    // 뭐가 제일 많이 나왔는지 확인
    int frequent_index = 0;
    int max = count[0];
    for (int i = 0; i < n; i++)
    {
        if (max < count[i])
        {
            max = count[i];
            frequent_index = i;
        }
    }

    return str[frequent_index];
}

int main()
{
    string str = "hello world";
    char c = mostFrequentChar(str);
    cout << c << endl;
    return 0;
}
