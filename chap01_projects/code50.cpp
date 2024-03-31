#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>
#include <algorithm>
using namespace std;

string trim(string str);
void tolowercase(string &str);

int main() {
    ifstream infile("input35.txt");
    string str;
    vector<string> words;
    
    while(infile >> str) {
        
        str = trim(str);
        if (str.length() > 0) {
            tolowercase(str);
            auto it = find(words.begin(), words.end(), str);
            if (it == words.end())
                words.push_back(str);
        }
    }

    infile.close();

    for (auto word: words)
        cout << word << endl;
    return 0;
}

// wordList 함수
string trim(string str) {
    int s = 0, t = str.length()-1;
    while (s < str.length() && !isalnum(str[s]))
        s++;
    
    while(t >= 0 && !isalnum(str[t]))
        t--;
    
    if (s <= t)
        return str.substr(s, t-s+1);
    else
        return "";
}

// 참조에 의한 호출(대량의 데이터가 복사회는 것을 막기 위함)
void tolowercase(string &str) {
    for (int i = 0; i < str.length(); i++)
        str[i] = tolower(str[i]);
}
