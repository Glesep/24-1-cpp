#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> words;

    // 문자열에 단어 입력
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        words.push_back(str);
    }

    // 조건에 따른 문자열 정렬 (bubble sort)
    for (int i = words.size()-1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (words[j].size() > words[j+1].size() || (words[j].size() == words[j+1].size() && words[j] > words[j+1]))
            {
                string tmp = words[j];
                words[j] = words[j+1];
                words[j+1] = tmp;
            }
        }
    }

    
    for (string str: words)
    {
        cout << str << endl;
    }

    return 0;
}