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

