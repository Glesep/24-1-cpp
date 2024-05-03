#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <cctype>
using namespace std;
// ofstream 써야될듯
// 이차원 벡터에 값을 넣는법 >> 벡터를 요소로 하는 벡터 a와 일반 벡터 b를 만든다.
// 비어있는 b를 먼저 a로 넣는다.
// a[0]로 해서 넣고 싶은 값을 넣는다. 

int main()
{
    ifstream infile("table.txt");
 
    // 읽기
    // 단어만 받아오기?
    vector<vector<string>> table;           // [행][렬]으로 표현할 것
    vector<string> col;                     // 열에 해당하는 벡터 (빈 벡터)
    string str;
    int rows, cols;

    getline(infile, str);                   // 첫번쨰 줄 받아오기
    
    // 문자열을 stream으로 변환, 타입에 맞게 넣을 수 있음
    istringstream iss(str);
    iss >> rows >> cols;

    //find 함수를 이용해서 & 추적
    for (int i = 0; i < rows; i++)
    {
        getline(infile, str);                   // 라인을 받아옴(행)
        int index = 0;
        table.push_back(col);

        for (int j = 0; j < cols; j++)
        {
            auto indexAnd = str.find('&', index);                    // & 추적    
            table[i].push_back(str.substr(index, indexAnd-index));   // table[i] 벡터에 저장
            index = indexAnd + 1;
        }
       
    }
    
    // ================================================================================
    // 단어만 남기기
    for (int i = 0; i< rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            string tmp = table[i][j];
            int s = 0, t = table[i][j].length()-1;
            while (s < tmp.length() && !isalnum(tmp[s]))                // 알파벳이거나 숫자가 아니고, s가 tmp길이보다 작은동안, (앞에서 줄여가기)
                s++;
        
            while (t >= 0 && !isalnum(tmp[t]))                          // t가 0보다 크고 알파벳이나 숫자가 아닐 때. (뒤에서 줄여가기)
                t--;
            
            if (s <= t)
            {
                table[i][j] = table[i][j].substr(s, t-s+1);
            }
        }
    }
    
    for (int j = 0; j < cols; j++)
    {
        int lengthMax = 0;
        for (int i = 0; i < rows; i++)
        {
            int tmpLength = table[i][j].length();
            // 길이 갱신
            if (tmpLength > lengthMax)
                lengthMax = tmpLength;
        }
        // space 추가
        for (int i = 0; i < rows; i++)
        {
            int space = lengthMax - table[i][j].length();
            for (int k = 0; k <= space; k++)
            {
                table[i][j] += " ";
            }
        }
    }
    
    infile.close();

    ofstream outfile("output.txt");
    // 쓰기
    // 제일 긴 글자가 기준, 기준 길이만큼 스페이스바 추가

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            outfile << table[i][j];
        }
        outfile << endl;
    }
    outfile.close();
    
    return 0;
}