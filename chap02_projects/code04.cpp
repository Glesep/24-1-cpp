#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

class Keyword {
public:
    string word;
    vector<int> lines;
};
vector<Keyword> indices;

// 함수 미리 선언
void makeIndex(string &fileName);
void handle_find(string &keyword);
void addWord(string &word, int lineNum);
vector<Keyword>::iterator findWord(string &keyword);
void saveAs(string &fileName);
vector<string> split_line(string &line);


int main() {
    string command;
    while(1) {
        cout << "$ ";
        cin >> command;
        // 커멘드에 따라 다른 함수 실행 
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
// 인덱스 만들기
void makeIndex(string &fileName) {
    ifstream theFile(fileName);
    int lineNum = 0;
    string line;
    while (getline(theFile, line)) {
        vector<string> tokens = split_line(line);
        for (auto s: tokens)
            // 공백이 tokenizing 되는 경우를 제외
            if (s.length() > 0)
                addWord(s, lineNum);
        lineNum++;
    }
    theFile.close();
}
// 라인에서 문자만 뽑아주기 꼭 기억!!!
vector<string> split_line(string &line) {
    
    vector<string> tokens;
    // 문자열 line을 하나의 stream 객체로 만들기 >> sstream으로부터 문자열 읽어오기
    stringstream sstream(line);
    string str;

    while (getline(sstream, str, ' '))        // 구분자 기준으로 잘라 읽기
        tokens.push_back(str);
    
    return tokens;
}
// 단어를 추가하기
void addWord(string &word, int lineNum) {
    auto it = findWord(word);

    if (it != indices.end())
        it->lines.push_back(lineNum);
    else {
        Keyword tmp;
        tmp.word = word;
        tmp.lines.push_back(lineNum);

        indices.push_back(tmp);
    }
}
// 단어 찾기
vector<Keyword>::iterator findWord(string &keyword) {
    auto it = indices.begin();
    while (it != indices.end() && it->word != keyword)
        it++;

    return it;
}

void handle_find(string &keyword) {
    auto it = findWord(keyword);
    if (it != indices.end()) {
        cout << "The word " << keyword << " appears " <<
            it->lines.size() << " times in lines: ";
        // 단어가 어떤 라인 번호에서 나왔나 출력
        for (auto v : it->lines)
            cout << v << ", ";
        cout << endl;
    }
    else cout << "The word " << keyword << " doesn't appear." << endl;
}

void saveAs(string &fileName) {
    ofstream outFile(fileName);
    for (auto item: indices) {
        // 단어를 저장
        outFile << item.word << endl;
        // 단어가 나온 라인 숫자를 저장
        for (auto c : item.lines)
            outFile << c << " ";
        outFile << endl;
    }
    outFile.close();
}