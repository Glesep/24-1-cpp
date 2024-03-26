#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
using namespace std;
// ofstream 써야될듯

int main()
{
    ifstream infile("table.txt");
 
    // 읽기
    // 단어만 받아오기?
    vector<vector<string>> table;           // [행][렬]으로 표현할 것
    vector<string> col;                     // 열에 해당하는 벡터
    string str;
    int rows, cols;

    getline(infile, str);                   // 첫번쨰 줄 받아오기
    
    istringstream iss(str);
    iss >> rows >> cols;

    getline(infile, str, '&');              // 두번째 줄부터 시작
    col.push_back(str);
    cout << col[0] << endl;

    

    
    





    infile.close();

    ofstream outfile("output.txt");
    // 쓰기
    // 제일 긴 글자가 기준, 기준 길이만큼 스페이스바 추가
    outfile.close();




    return 0;
}