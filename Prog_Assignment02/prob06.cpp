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

// #include <iostream>
// #include <fstream>
// #include <string>
// #include <vector>
// #include <cctype>
// #include <algorithm>

// using namespace std;
// vector<string> words;

// int main() {
//     string str;
//     ifstream infile("sample.txt");
//     while(infile >> str) {
            // 특수문자나 숫자 다 걷어내기
//         int s = 0, t = str.length()-1;;
//         while(s<str.length() && !isalnum(str[s]))
//             s++;
//         while(t>=0 && !isalnum(str[t]))
//             t--;
//          
//         if (s<=t) {
//                // pure_word 소문자화
//             string pure_word = str.substr(s, t-s+1);
//             for (int i=0; i<pure_word.length(); i++)
//                 pure_word[i] = tolower(pure_word[i]);
//               
//             auto it = words.begin();
//                // 사전식 정렬 
//             while(it != words.end() && *it < pure_word)
//                 it++;
//                // 겹치는가 확인
//             if (it != words.end() && *it==pure_word)
//                 continue;
//             words.insert(it, pure_word);
//         }
//     }
//     infile.close();

//     for (auto w: words)
//         cout << w << endl;
//     return 0;
// }

// //string trim(string str) {
// //    int s = 0, t = str.length()-1;;
// //    while(s<str.length() && !isalnum(str[s]))
// //        s++;
// //
// //    while(t>=0 && !isalnum(str[t]))
// //        t--;
// //
// //    if (s<=t)
// //        return str.substr(s, t-s+1);
// //    else
// //        return "";
// //}
// //
// //void tolowercase(string str) {
// //    for (int i=0; i<str.length(); i++)
// //        str[i] = tolower(str[i]);
// //}