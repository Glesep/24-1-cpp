#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;


string checkWord(string str, vector<string> &words);

class PuzzleClass {
public:
    vector<vector<string>> puzzle;
    vector<string> duplication;
    

    // 단어 중복 검사
    bool duplicate(string str, vector<string> duplication) {
        for (int i = 0; i < duplication.size(); i++) {
            if (duplication[i] == str) {
                return true;
            }
        }
        return false;
    }
    // 수평 검사 함수
    void checkHr(vector<string> &words) {
        // 행
        for (int i = 0; i < puzzle.size(); i++) {
            // 단어를 기준삼는 인덱스 j
            for (int j = 0; j < puzzle[i].size(); j++) {
                string compareStr = "";
                // 실질적인 비교 인덱스 k
                for (int k = j; k < puzzle[i].size(); k++) {
                    // 정방향 검사
                    compareStr += puzzle[i][k];
                    string check = checkWord(compareStr, words);
                    
                    if (check != "") {
                        bool isDuplicated = duplicate(check, duplication);
                        if (!isDuplicated) {
                            cout << check << endl;
                            duplication.push_back(check);
                        }
                    }
                    // 역방향 검사
                    string compareStr_reverse = compareStr;
                    reverse(compareStr_reverse.begin(), compareStr_reverse.end());
                    string check_reverse = checkWord(compareStr_reverse, words);
                    if (check_reverse != "") {
                        bool isDuplicated = duplicate(check_reverse, duplication);
                        if (!isDuplicated) {
                            cout << check_reverse << endl;
                            duplication.push_back(check_reverse);
                        }
                    }
                }
            }
        }
    }
    // 수직 검사 함수
    void checkVt(vector<string> &words) {
        // 열
        for (int i = 0; i < puzzle.size(); i++) {
            // 단어를 기준삼는 인덱스 j
            for (int j = 0; j < puzzle[i].size(); j++) {
                string compareStr = "";
                // 실질적인 비교 인덱스 k
                for (int k = j; k < puzzle[i].size(); k++) {
                    // 정방향 검사
                    compareStr += puzzle[k][i];
                    string check = checkWord(compareStr, words);
                    if (check != "") {
                        // 중복 검사
                        bool isDuplicated = duplicate(check, duplication);
                        if (!isDuplicated) {
                            cout << check << endl;
                            duplication.push_back(check);
                        }
                    }
                    // 역방향 검사
                    string compareStr_reverse = compareStr;
                    // 단어를 뒤집어주는 reverse 함수 (<algorithm>)
                    reverse(compareStr_reverse.begin(), compareStr_reverse.end());
                    string check_reverse = checkWord(compareStr_reverse, words);
                    if (check_reverse != "") {
                        bool isDuplicated = duplicate(check_reverse, duplication);
                        if (!isDuplicated) {
                            cout << check_reverse << endl;
                            duplication.push_back(check_reverse);
                        }
                    }
                }
            }
        }
    }
    // 대각선 체크
    void checkDiagonal(vector<string> &words) {
        vector<string> Diagonal;                  // 우하단 대각선 선언
        
        // 대각선 시작 좌표
        int x = 0, y = 0;
        // 대각선의 내용을 벡터에 담기
        while (x < puzzle.size()) {
            putDiagonal_1(x, y, Diagonal);

            // 행 비교 함수와 비슷
            for (int j = 0; j < Diagonal.size(); j++) {
                string compareStr = "";
                // 실질적인 비교 인덱스 k
                for (int k = j; k < Diagonal.size(); k++) {
                    // 정방향 검사
                    compareStr += Diagonal[k];
                    string check = checkWord(compareStr, words);
                    if (check != "") {
                        // 중복 검사
                        bool isDuplicated = duplicate(check, duplication);
                        if (!isDuplicated) {
                            cout << check << endl;
                            duplication.push_back(check);
                        }
                    }
                    // 역방향 검사
                    string compareStr_reverse = compareStr;
                    // 단어를 뒤집어주는 reverse 함수 (<algorithm>)
                    reverse(compareStr_reverse.begin(), compareStr_reverse.end());
                    string check_reverse = checkWord(compareStr_reverse, words);
                    if (check_reverse != "") {
                        bool isDuplicated = duplicate(check_reverse, duplication);
                        if (!isDuplicated) {
                            cout << check_reverse << endl;
                            duplication.push_back(check_reverse);
                        }
                    }
                }
            }
            x++;
        }
        x = 0;
        // 남은 한 벡터 지워주기
        Diagonal.pop_back();

        while (y < puzzle.size()) {
            putDiagonal_1(x, y, Diagonal);

            // 행 비교 함수와 비슷
            for (int j = 0; j < Diagonal.size(); j++) {
                string compareStr = "";
                // 실질적인 비교 인덱스 k
                for (int k = j; k < Diagonal.size(); k++) {
                    // 정방향 검사
                    compareStr += Diagonal[k];
                    string check = checkWord(compareStr, words);
                    if (check != "") {
                        // 중복 검사
                        bool isDuplicated = duplicate(check, duplication);
                        if (!isDuplicated) {
                            cout << check << endl;
                            duplication.push_back(check);
                        }
                    }
                    // 역방향 검사
                    string compareStr_reverse = compareStr;
                    // 단어를 뒤집어주는 reverse 함수 (<algorithm>)
                    reverse(compareStr_reverse.begin(), compareStr_reverse.end());
                    string check_reverse = checkWord(compareStr_reverse, words);
                    if (check_reverse != "") {
                        bool isDuplicated = duplicate(check_reverse, duplication);
                        if (!isDuplicated) {
                            cout << check_reverse << endl;
                            duplication.push_back(check_reverse);
                        }
                    }
                }
            }
            y++;
        }
        y = 5;
        // 나머지 한 벡터 지워주기
        Diagonal.pop_back();

        while (x < puzzle.size()) {
            putDiagonal_2(x, y, Diagonal);

            // 행 비교 함수와 비슷
            for (int j = 0; j < Diagonal.size(); j++) {
                string compareStr = "";
                // 실질적인 비교 인덱스 k
                for (int k = j; k < Diagonal.size(); k++) {
                    // 정방향 검사
                    compareStr += Diagonal[k];
                    string check = checkWord(compareStr, words);
                    if (check != "") {
                        // 중복 검사
                        bool isDuplicated = duplicate(check, duplication);
                        if (!isDuplicated) {
                            cout << check << endl;
                            duplication.push_back(check);
                        }
                    }
                    // 역방향 검사
                    string compareStr_reverse = compareStr;
                    // 단어를 뒤집어주는 reverse 함수 (<algorithm>)
                    reverse(compareStr_reverse.begin(), compareStr_reverse.end());
                    string check_reverse = checkWord(compareStr_reverse, words);
                    if (check_reverse != "") {
                        bool isDuplicated = duplicate(check_reverse, duplication);
                        if (!isDuplicated) {
                            cout << check_reverse << endl;
                            duplication.push_back(check_reverse);
                        }
                    }
                }
            }
            x++;
        }
        x = 0;
        // 나머지 한 벡터 지워주기
        Diagonal.pop_back();

        while (y >= 0) {
            putDiagonal_2(x, y, Diagonal);

            // 행 비교 함수와 비슷
            for (int j = 0; j < Diagonal.size(); j++) {
                string compareStr = "";
                // 실질적인 비교 인덱스 k
                for (int k = j; k < Diagonal.size(); k++) {
                    // 정방향 검사
                    compareStr += Diagonal[k];
                    string check = checkWord(compareStr, words);
                    if (check != "") {
                        // 중복 검사
                        bool isDuplicated = duplicate(check, duplication);
                        if (!isDuplicated) {
                            cout << check << endl;
                            duplication.push_back(check);
                        }
                    }
                    // 역방향 검사
                    string compareStr_reverse = compareStr;
                    // 단어를 뒤집어주는 reverse 함수 (<algorithm>)
                    reverse(compareStr_reverse.begin(), compareStr_reverse.end());
                    string check_reverse = checkWord(compareStr_reverse, words);
                    if (check_reverse != "") {
                        bool isDuplicated = duplicate(check_reverse, duplication);
                        if (!isDuplicated) {
                            cout << check_reverse << endl;
                            duplication.push_back(check_reverse);
                        }
                    }
                }
            }
            y--;
        }
        y = 0;
    }
     
    void putDiagonal_1(int x, int y, vector<string> &Diagonal) {
         
        // 0,0일 땐 그냥 삽입하기
        if (x == 0 && y == 0) {
            for (int i = 0 ; i < puzzle.size(); i++) {
                Diagonal.push_back(puzzle[x][y]);
                x++;
                y++;
            }  
            return; // 없으면 x, y가 양수이므로 else문으로 내려가 오류를 일으킨다.
        }
        // 아닐 땐 삽입 전 크기 하나 줄이기 
        else {
            Diagonal.pop_back();
            for (int i = 0; i < Diagonal.size(); i++) {
                Diagonal[i] = puzzle[x][y];
                x++;
                y++;
            }
            return;
        }
    }

    void putDiagonal_2(int x, int y, vector<string> &Diagonal) {
         
        // 0,0일 땐 그냥 삽입하기
        if (x == 0 && y == 5) {
            for (int i = 0 ; i < puzzle.size(); i++) {
                Diagonal.push_back(puzzle[x][y]);
                x++;
                y--;
            }  
            return; // 없으면 x, y가 양수이므로 else문으로 내려가 오류를 일으킨다.
        }
        // 아닐 땐 삽입 전 크기 하나 줄이기 
        else {
            Diagonal.pop_back();
            for (int i = 0; i < Diagonal.size(); i++) {
                Diagonal[i] = puzzle[x][y];
                x++;
                y--;
            }
            return;
        }
    }
};

int main() {
    vector<string> words;
    ifstream infile1("dictionary.txt");
    string str;
    while(infile1 >> str) {
        words.push_back(str);
    }
    infile1.close();
   
    
    ifstream infile2("puzzle.txt");
    getline(infile2, str);                         // 그리드 크기 파악
    istringstream iss(str);
    int gridSize;
    iss >> gridSize;
   
    //===================================================================================================================================
    

    // vector<vector<string>> puzzle(vector<string>()); 선언 시 이 형태 절대 아님!!!! XXXX
    PuzzleClass puz;
    
    puz.puzzle.push_back(vector<string>());
    int size = 1, index = 0;

    // puzzle 입력
    while (infile2 >> str) {
        puz.puzzle[index].push_back(str);

        if(size == gridSize) {
            size = 1;
            index++;
            puz.puzzle.push_back(vector<string>());
        }

        else
            size++;
    }
    // 마지막에 빈 벡터 추가된 것 빼주기
    puz.puzzle.pop_back();

    
    // 여기까지 ok
    //====================================================================================================================================
    puz.checkHr(words);
    puz.checkVt(words);
    puz.checkDiagonal(words);
   
    infile2.close();
    return 0;
}

string checkWord(string str, vector<string> &words) {
    for (auto it = words.begin(); it < words.end(); it++) {
        if ((*it) == str) {
            // ** 문자열 반환한다고 함수가 문자열이 되는 건 아님 **
            return str;
        }
    }
    return "";
}

 