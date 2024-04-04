#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <cctype>
using namespace std;

// 전역 변수
vector<string> words;
// lineContents의 첫번째 인덱스: 단어가 저장된 순서(단어 분별용) == words의 인덱스 
vector<vector<string>> lineContents;

// 함수 미리 선언
void makeIndex(string fileName);
void handle_find(string keyword);
string makePureWord(string word);
void addWord(string word, string lineContent);
int findWord(string keyword);
void saveAs(string fileName);
vector<string> split_line(string line, char delimiter);
void sortWords(vector<string> &words, vector<vector<string>> &lineContents);


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
// =============================================================== 여기부터 함수 부분 =======================================================================
// 인덱스 만들기
void makeIndex(string fileName) {
    ifstream theFile(fileName);
    int lineNum = 0;
    string line;
    while (getline(theFile, line)) {
        // 라인을 lineContent에 저장
        string lineContent = to_string(lineNum) + ": " + line;
        vector<string> tokens = split_line(line, ' ');
        for (auto s: tokens)
            // 공백이 tokenizing 되는 경우를 제외
            if (s.length() > 0)
                addWord(s, lineContent);
        lineNum++;
    }
    sortWords(words, lineContents);
    theFile.close();
}
// 라인에서 문자만 뽑아주기
vector<string> split_line(string line, char delimiter) {
    
    vector<string> tokens;
    // 문자열 line을 하나의 stream 객체로 만들기 >> sstream으로부터 문자열 읽어오기
    stringstream sstream(line);
    string str;

    while (getline(sstream, str, delimiter))                     // 구분자 기준으로 잘라 읽기
        tokens.push_back(str);
    
    return tokens;
}
// 단어 뽑아내기
string makePureWord(string word) {
    int s = 0, t = word.length()-1;
    while (s < word.length() && !isalnum(word[s]))               // 알파벳이거나 숫자가 아니고, s가 str길이보다 작은동안, (앞에서 줄여가기)
        s++;
        
    while (t >= 0 && !isalnum(word[t]))                          // t가 0보다 크고 알파벳이나 숫자가 아닐 때. (뒤에서 줄여가기)
        t--;
    
    string pure_word = "";
    // if도 스코프 생각하기
    if (s <= t)
    {
        pure_word = word.substr(s, t-s+1);                      // 시작 위치: s, 문자의 개수(인덱스 포함): t-s+1

        for (int i = 0; i < pure_word.length(); i++)
            pure_word[i] = tolower(pure_word[i]);               // cctype이 제공, 소문자로 변환
        
    }
    return pure_word;
}
// 단어를 추가하기
void addWord(string word, string lineContent) {
    // 단어만 뽑아내기
    string pureWord = makePureWord(word);

    int index = findWord(pureWord);

    if (index > -1)
    // words의 인덱스와 lineContents의 인덱스가 같다.
        lineContents[index].push_back(lineContent);
    else {
        // 길이가 3 이상이면 words 벡터에 pureWord 추가
        if (pureWord.length() >= 3) {
            words.push_back(pureWord);
            // tmp 벡터에 lineContent를 저장 (새로운 벡터를 파줘야됨)
            vector<string> tmp = {lineContent};
            // lineContents에 tmp를 저장
            lineContents.push_back(tmp);
        }
    }
}
// 단어 찾기
int findWord(string word) {

    // 입력된 단어 소문자로 바꾸기
    for (int i = 0; i < word.length(); i++) {
        // tolower 사용법 알기
        word[i] = tolower(word[i]);
    }

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
            lineContents[index].size() << " times in lines: " << endl;
        cout << lineContents[index][0] << endl;
        // 단어가 어떤 라인에서 나왔나 출력 (리인번호 + 라인 내용)
        for (int i = 1; i < lineContents[index].size(); i++) {
            if (lineContents[index][i-1] != lineContents[index][i]) {
                cout << lineContents[index][i] << endl;
            }
        }    
    }
    else cout << "The word " << keyword << " doesn't appear." << endl;
}
// Bubble Sort Algorithm
void sortWords (vector<string> &words, vector<vector<string>> &lineContents) {
    for (int i = words.size()-1; i > 0; i--) {
        for (int j = 0; j < i; j++) {
            if (words[j] > words[j+1]) {
                // words 인덱스 바꾸기
                string tmp1 = words[j];
                words[j] = words[j+1];
                words[j+1] = tmp1;
                // linContents 인덱스 바꾸기 (words의 인덱스가 가리키는 단어와 같은 단어를 가리키기 때문)
                vector<string> tmp2 = lineContents[j];
                lineContents[j] = lineContents[j+1];
                lineContents[j+1] = tmp2;
            }
        }
    }
}

