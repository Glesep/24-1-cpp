#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

int main()
{
    vector<string> words;
    string str;
    while(1)
    {
        cin >> str;
        if (str == "exit")
            break;
        words.push_back(str);
    }

    sort(words.begin(), words.end());                       // 사전식 순서로 정렬

    for (auto s: words)
        cout << s << " ";
    cout << endl;

    return 0;
}