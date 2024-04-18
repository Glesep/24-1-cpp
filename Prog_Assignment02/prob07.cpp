#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> words;
    string word;

    while (1)
    {
        cin >> word;
        if (word == "exit")
            break;
        
        bool duplicate = false;
        for (int i = 0; i < words.size(); i++)
        {
            if (word == words[i])
            {
                duplicate = true;
                cout << "duplicate" << endl;
                break;
            }
        }

        if (!duplicate)
        {
            words.push_back(word);
            sort(words.begin(), words.end());

            for (int i = 0; i < words.size(); i++)
                cout << words[i] << " ";
            cout << endl; 
        }

    }

    return 0;
}

// #include <iostream>
// #include <string>
// #include <vector>
// #include <algorithm>

// using namespace std;
// vector<string> words;

// int main() {
//     string str;
//     while(1) {
//         cin >> str;
//         if (str == "exit") break;
//         auto it = words.begin();
//         // 기존 있던 단어보다 str이 뒤라면 it++
//         while(it != words.end() && *it < str)
//             it++;
//         // 중간에서 똑같은 단어 찾았을 경우
//         if (it != words.end() && *it==str) {
//             cout << "duplicate" << endl;
//             continue;
//         }
//         words.insert(it, str);
//         for (auto w: words)
//             cout << w << ' ';
//         cout << endl;
//     }

//     return 0;
// }
