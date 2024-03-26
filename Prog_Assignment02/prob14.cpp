#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> words;
    // 파일 불러오기
    ifstream infile("harry.txt");

    // 중복 없이 모든 단어 목록 벡터에 저장
    string str;
    while (infile >> str)
    {   
        bool duplclicate = false;
        for (int i = 0; i < words.size(); i++)
        {
            if (str == words[i])
            {
                duplclicate = true;
                break;
            }
        }

        if(!duplclicate)
        {
            words.push_back(str);
        }
    }
    infile.close();
    // vector 사전식 정렬
    sort(words.begin(), words.end());

    string newWord;
    cin >> newWord;
    int count = 0;

    // 접두사 유무 체크
    for (int i = 0; i < words.size(); i++)
    {
        // 접두사인지 확인
        bool prefix = true;
        for (int j = 0; j < newWord.size(); j++)
        {
            if (newWord[j] != words[i][j])
            {
                prefix = false;
                break;
            }
        }
        //접두사인 경우
        if (prefix)
        {
            cout << words[i] << endl;
            count++;
        }
    }
    cout << count << endl;

    return 0;
}