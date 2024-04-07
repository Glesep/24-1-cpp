#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    // insert를 이용 사이에 끼우기 >> code25.cpp와 비교
    vector<string> words;
    string str;
    while(1)
    {
        cin >> str;
        if (str == "exit")
            break;
        auto it = words.begin();
        while (it != words.end() && *it < str)
            it++;
        // 다 훑었는데 안나왔다면
        if (it == words.end())
            words.push_back(str);
        // 나왔다면
        else
            words.insert(it, str);
        
        for (auto s: words)
            cout << s << " ";
        cout << endl;
    }
}