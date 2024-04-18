#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;
const int MAX = 1000;

int main()
{
    ifstream infile("sample_lines.txt");                                     // input34.txt 파일을 읽어서 infile이라는 객체에 넣는다.

    string lines[MAX];
    int count_words[MAX] = {0};

    string line;
    int n = 0;



    // 공백도 읽어들임, 마지막 공백 라인은 \n이 잆으므로 읽어지지 않는다.
    while (getline(infile, line))                                       // 파일로부터 한 라인을 읽는다. 파일의 끝에 도달하면 false가 된다.
    {
        // 한 라인에서 불필요한 공백 없애기
        for (int i = 0; i < line.length(); i++)
        {
            // 맨 앞 공백 지우기
            if (isspace(line[0]))
            {
                line.erase(0,1);
                i--;
            }
            
            // 앞이 공백이고 뒤가 문자나 숫자가 아닌 경우
            else if (isspace(line[i]) && !isalnum(line[i+1]))
            {   
                line.erase(i,1);
                i--;
            }

            // 맨 뒤가 공백인 경우
            else if (isspace(line.back()))
                line.erase(line.length()-1, 1);  
        }
        
        if (line != "")
        {
            lines[n] = line;
            count_words[n] = 1;
            for (int i = 0; i < line.length(); i++)
            {
                if (isspace(line[i]))
                    count_words[n]++;
            }
            n++;
        }
       
       
    }                                                                                
    
    infile.close();
    for (int i = n-1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (count_words[j] < count_words[j+1])                          // 작은 게 뒤로 가야함                                             
            {
                int tmp1 = count_words[j];
                count_words[j] = count_words[j+1];
                count_words[j+1] = tmp1;

                string tmp2 = lines[j];
                lines[j] = lines[j+1];
                lines[j+1] = tmp2;
            }
        }
    }

    // 마지막 n은 빈 요소
    for (int i = 0; i < n; i++)
        cout << lines[i] << ":" << count_words[i] << endl;
    
    return 0;
}

// #include <iostream>
// #include <fstream>
// #include <string>
// #include <vector>
// #include <cctype>
// using namespace std;

// vector<vector<string>> lines;

// void tolowercase(string &str) {
//     for (char &c: str)
//         c = tolower(c);
// }

// // 문자를 단어로 나눠 벡터에 저장
// vector<string> split_line(string &line) {
//     vector<string> tokens;
//     int start = 0, end;
//     while((end = line.find(' ', start)) != -1) {
//         string t = line.substr(start, end - start);
//         if (t.size() > 0)
//             tokens.push_back(t);
//         start = end + 1;
//     }
//     string t = line.substr(start);
//     if (t.size()>0)
//         tokens.push_back(line.substr(start));
//     return tokens;
// }

// // 나눈 단어들을 차례로 출력
// void print_line(vector<string> &item) {
//     for(auto t: item) {
//         cout << t << ' ';
//     }
//     cout << ':' << item.size() << endl;
// }

// int main() {
//     string line;
//     ifstream infile("sample_lines.txt");
//     while(getline(infile, line)) {
//         vector<string> tokens = split_line(line);
//         if (tokens.size() > 0)
//             // 단어들을 한 벡터에 삽입
//             lines.push_back(tokens);
//     }
//     infile.close();
//     // 단어 개수 비교
//     for (int i=lines.size()-1; i>0; i--) {
//         for (int j=0; j<i; j++) {
//             if (lines.at(j).size() < lines.at(j+1).size())
//                 swap(lines.at(j), lines.at(j+1));
//         }
//     }
//     // 라인 출력
//     for(auto &item: lines) {
//         print_line(item);
//     }
//     return 0;
// }

