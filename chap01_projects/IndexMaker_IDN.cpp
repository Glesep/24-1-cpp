#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

// 전역 변수
vector<string> words;
// lineNums의 첫번째 인덱스: 단어가 저장된 순서(단어 분별용) == words의 인덱스
vector<vector<int>> lineNums;

// 함수 미리 선언
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
// 라인에서 문자만 뽑아주기
vector<string> split_line(string line, char delimiter) {
    
    vector<string> tokens;
    // 문자열 line을 하나의 stream 객체로 만들기 >> sstream으로부터 문자열 읽어오기
    stringstream sstream(line);
    string str;

    while (getline(sstream, str, delimiter))        // 구분자 기준으로 잘라 읽기
        tokens.push_back(str);
    
    return tokens;
}
// 단어를 추가하기
void addWord(string word, int lineNum) {
    int index = findWord(word);

    if (index > -1)
    // words의 인덱스와 lineNums의 인덱스가 같다.
        lineNums[index].push_back(lineNum);
    else {
        // words 벡터에 word 추가
        words.push_back(word);
        // tmp 벡터에 lineNum(word가 나타난 라인 번호)를 저장
        vector<int> tmp = {lineNum};
        // lineNums에 tmp를 저장
        lineNums.push_back(tmp);
    }
}
// 단어 찾기
int findWord(string word) {
    for (int i = 0; i < words.size(); i++) {
        // vector인 words 중 하나랑 겹친다면 인덱스 반환
        if (words[i] == word)
            return i;
    }
    return -1;
}

void handle_find(string keyword) {
    int index = findWord(keyword);
    if (index != -1) {
        cout << "The word " << keyword << " appears " <<
            lineNums[index].size() << " times in lines: ";
        // 단어가 어떤 라인 번호에서 나왔나 출력
        for (auto v : lineNums[index])
            cout << v << ", ";
        cout << endl;
    }
    else cout << "The word " << keyword << " doesn't appear." << endl;
}

void saveAs(string fileName) {
    ofstream outFile(fileName);
    for (int i = 0; i < words.size(); i++) {
        // 단어를 저장
        outFile << words[i] << endl;
        // 단어가 나온 라인 숫자를 저장
        for (auto c : lineNums[i])
            outFile << c << " ";
        outFile << endl;
    }
    outFile.close();
}