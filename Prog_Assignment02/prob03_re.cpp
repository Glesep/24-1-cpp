#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include <string>
#include <cctype>
using namespace std;

void toLowerChar(string &str) {
    for (int i = 0; i < str.length(); i++) {
        str[i] = tolower(str[i]);
    } 
}


int main() {
    vector<pair<string, int>> checkStr;

    ifstream infile("input3.txt");
    string str;
    while (infile >> str) {
        // 단어 넣기
        toLowerChar(str);
        bool duplicated = false;
        for (int i = 0; i < (int)checkStr.size(); i++) {
            // 똑같은 단어 있을 경우 개수 늘리기
            if (checkStr[i].first == str) {
                checkStr[i].second++;
                duplicated = true;
            }
        }

        if (!duplicated) {
            pair<string, int> p(str, 1);
            checkStr.push_back(p);
        }
    }
    infile.close();

    for (int i = (int)checkStr.size()-1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if ((checkStr[j].second < checkStr[j+1].second) || (checkStr[j].second == checkStr[j+1].second && checkStr[j].first > checkStr[j+1].first)) {
                swap(checkStr[j], checkStr[j+1]);
            }
        }
    }

    for (auto i : checkStr) 
        cout << i.first << ":" << i.second << endl;
    
    return 0;
}