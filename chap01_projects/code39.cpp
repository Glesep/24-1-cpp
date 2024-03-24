#include <iostream>
#include <vector>
#include <string>

using namespace std;
int main()
{
    vector<string> words;
    string str;
    vector<int> count;

    // cin에서 끝을 알려주는 방법: ctrl + z
    while(cin >> str)
    {
        // ===========================================================================================================================================
        // 나의 풀이
        // int s = 0, t = str.length()-1;
        // while (s < str.length() && !isalnum(str[s]))                // 알파벳이거나 숫자가 아니고, s가 str길이보다 작은동안, (앞에서 줄여가기)
        //     s++;
        
        // while (t >= 0 && !isalnum(str[t]))                          // t가 0보다 크고 알파벳이나 숫자가 아닐 때. (뒤에서 줄여가기)
        //     t--;
    
        // if (s <= t)
        // {
        //     string pure_word = str.substr(s, t-s+1);                // 시작 위치: s, 문자의 개수(인덱스 포함): t-s+1

        //     for (int i = 0; i < pure_word.length(); i++)
        //         pure_word[i] = tolower(pure_word[i]);               // cctype이 제공, 소문자로 변환 

        //     bool found = false;                                     // 중복 단어 찾았다라는 기준
        //     for (int i = 0; i < words.size(); i++)
        //     {
        //         if (words[i] == pure_word)                          // 이미 등록된 문자열인지 검사
        //         {
        //             found = true;
        //             count[i]++;
        //             break;
        //         }
        //     }
        //     if(!found)                                              // 목록에 없는 문자열은 목록에 추가 후 빈도수 체크
        //     {
        //         words.push_back(pure_word);
        //         count.push_back(1);
                
        //     }    
        // }
        // =========================================================================================================================================== 

        int j = 0;
        for (; j < words.size(); j++)
            if (words[j] == str)
                break;
        
        // 단어가 나온적이 있다면
        if (j < words.size())
            count[j]++;
        // 단어가 나온적이 없다면
        else
        {
            words.push_back(str);
            count.push_back(1);
        }
    }

    for(int i = 0; i < words.size(); i++)
        cout << words[i] << " " << count[i] << endl;
    



    return 0;
}