#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 하나라도 다르면 break;
// 제일 짧은 글자 길이 기준
int main()
{
    int n;
    cin >> n;                                       // n < 100

    vector<string> words;
    string str;
    // 값 입력
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        words.push_back(str);
    }
        

    int lengthMin = words[0].length();
    // 요소 중 가장 짧은 글자 길이 구하기
    for (auto str: words)
    {
        if (str.length() < lengthMin)
        {
            lengthMin = str.length();
        }
    }

    int duplicatePosition = -1;
    // 가장 짧은 글자 길이 기준
    for (int i = 0; i < lengthMin; i++)                 // 글자 길이
    {   
        bool duplicate = true;
        for (int j = 1; j < words.size(); j++)          // 글자 종류
        {
            if (words[j][i] != words[0][i])             // 같지 않을 때,
            {   
                duplicate = false;
                break;
            }
        }

        if (duplicate)
        {
            duplicatePosition = i;                      // 현재 i까진 겹침
        }
    }

    if (duplicatePosition == -1)
        cout << "nothing" << endl;
    else
    {
        for (int i = 0; i <= duplicatePosition; i++)
            cout << words[0][i];
        cout << endl;
    }

    return 0;
}