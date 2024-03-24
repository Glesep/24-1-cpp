#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <algorithm>
#include <cctype>
using namespace std;

int main()
{
    vector<string> words;
    string word;

    ifstream infile("sample.txt");                                                  // "sample.txt" 파일 열기

    while (infile >> word)
    {
        int start = 0, end = word.length()-1;
        
        // 앞과 뒤에서 문자만 있는 곳까지 범위를 좁힌다.
        while (start < word.length() && !isalnum(word[start]))                      
            start++;
        while (end >= 0 && !isalnum(word[end]))
            end--;

        if (start <= end)
        {
            string pureWord = word.substr(start, end-start+1);                      // 시작 위치부터 end-start+1개만큼 자른다.
            // 소문자 바꿔주기
            for (int i = 0; i < pureWord.length(); i++)
                pureWord[i] = tolower(pureWord[i]);

            bool found = false;
            for (int i = 0; i < words.size(); i++)
            {
                if (words.at(i) == pureWord)
                {
                    found = true;
                    break;
                }
            }
            if (!found)
                words.push_back(pureWord);
        }
    }

    infile.close();

    sort(words.begin(), words.end());                                               // 파일 사전식 정렬

    for (int i = 0; i < words.size(); i++)
        cout << words.at(i) << endl;


    return 0;
}