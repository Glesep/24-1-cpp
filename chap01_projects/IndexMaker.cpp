#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

// 전역 변수
vector<string> words;
vector<vector<int>> lineNums;

void makeIndex(string fileName);
void handle_find(string keyword);
void addWord(string word, int lineNum);
int findWord(string keyword);
void saveAs(string fileName);
vector<string> split_line(string line, char delimiter);


int main() {
    string command;
    while(1) {
        cout << "$ ";
        cin >> command;

        if (command == "read") {
            string fileName;
            cin >> fileName;
            makeIndex(fileName);
        }
        else if (command == "saveas") {
            string fileName;
            cin >> fileName;
            saveAs(fileName);
        }
        else if (command == "find") {
            string keyword;
            cin >> keyword;
            handle_find(keyword);
        }
        else if (command == "exit")
            break;
    }
    return 0;
}
// ===============================================================================================================

void makeIndex(string fileName) {
    ifstream theFile(fileName);
    int lineNum = 0;
    string line;
    while (getline(theFile, line)) {
        vector<string> tokens = split_line(line, ' ');
        for (auto s: tokens)
            // 공백이 tokenizing 되는 경우를 제외
            if (s.length() > 0)
                addWord(s, lineNum);
        lineNum++;
    }
    theFile.close();
}

vector<string> split_line(string line, char delimiter) {
    
    vector<string> tokens;
    // 문자열 line을 하나의 stream 객체로 만들기 >> sstream으로부터 문자열 읽어오기
    stringstream sstream(line);
    string str;

    while (getline(sstream, str, delimiter))        // 구분자 기준으로 잘라 읽기
        tokens.push_back(str);
    
    return tokens;
}

void addWord(string word, int lineNum) {
    int index = findWord(word);

    if (index > -1)
        lineNums[index].push_back(lineNum);
    else {
        words.push_back(word);
        vector<int> tmp = {lineNum};
        lineNums.push_back(tmp);
    }
}

int findWord(string word) {
    for (int i = 0; i < words.size(); i++) {
        if (words[i] == word)
            return i;
    }
    return -1;
}

void handle_find(string keyword) {
    int index = findWord(keyword);
    if (index != 1) {
        cout << "The word " << keyword << " appears " <<
            lineNums[index].size() << " times in lines: ";
        for (auto v : lineNums[index])
            cout << v << ", ";
        cout << endl;
    }
    else cout << "The word " << keyword << " doesn't appear." << endl;
}

void saveAs(string fileName) {
    ofstream outFile(fileName);
    for (int i = 0; i < words.size(); i++) {
        outFile << words[i] << endl;
        for (auto c : lineNums[i])
            outFile << c << " ";
        outFile << endl;
    }
    outFile.close();
}
