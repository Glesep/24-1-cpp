#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;
const int MAX = 1000;

int main()
{
    ifstream infile("input35.txt");
    string str;
    string words[MAX];
    int n = 0;

    // 한번에 한 단어씩 읽고싶을 때, 읽을 것이 없으면 false 반환
    while (infile >> str)
    {
        int s = 0, t = str.length()-1;
        while (s < str.length() && !isalnum(str[s]))                // 알파벳이거나 숫자가 아니고, s가 str길이보다 작은동안, (앞에서 줄여가기)
            s++;
        
        while (t >= 0 && !isalnum(str[t]))                          // t가 0보다 크고 알파벳이나 숫자가 아닐 때. (뒤에서 줄여가기)
            t--;
    
        if (s <= t)
        {
            string pure_word = str.substr(s, t-s+1);                // 시작 위치: s, 문자의 개수(인덱스 포함): t-s+1

            for (int i = 0; i < pure_word.length(); i++)
                pure_word[i] = tolower(pure_word[i]);               // cctype이 제공, 소문자로 변환 

            bool found = false;                                     // 중복 단어 찾았다라는 기준
            for (int i = 0; i < n; i++)
            {
                if (words[i] == pure_word)                          // 이미 등록된 문자열인지 검사ㅁ
                {
                    found = true;
                    break;
                }
            }
            if(!found)                                              // 목록에 없는 문자열만 목록에 추가
                words[n++] = pure_word;
        }
    }
    infile.close();

    for (int i = 0; i < n; i++)
        cout << words[i] << endl;

    return 0;
}
