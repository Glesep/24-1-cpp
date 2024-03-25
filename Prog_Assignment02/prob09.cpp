#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 한 줄을 받고 '\t'에서 끊을까??
// string 타입의 변수에 먼저 받아서 벡터로 넣어준다.
void Read_File(ifstream &infile, vector<string> &line)
{
    string str;
    while(getline(infile, str))
    {
        line.push_back(str);
    }
}


//"\t"을 기준으로 단어 나누기
// 설명은 한 줄로 되어 있으므로 해당하는 줄을 읽으면 되겠네
int main()
{
    ifstream infile("shuffled_dict.txt");
    vector<string> line;
    string str;
    cin >> str;

    Read_File(infile, line);

    // 단어를 기준으로 line를 사전식 정렬 (bubblesort)
    for (int i = line.size()-1; i > 0; i--)
    {
        
        for (int j = 0; j < i; j++)
        {
            int index1 = line[j].find('\t');
            int index2 = line[j+1].find('\t');
            
            if (line[j].substr(0, index1) > line[j+1].substr(0, index2))                          // 작은 게 뒤로 가야함                                             
            {
                string tmp = line[j];
                line[j] = line[j+1];
                line[j+1] = tmp;
            }
        }
    }

    
    for (int i = 0; i < line.size(); i++)
    {
        int index = line[i].find('\t');
        if (str == line[i].substr(0, index))
        {
            
            cout << "Found:" << endl;
            cout << str << ": " << line[i].substr(index);
        }
    }
    
    infile.close();



    return 0;
}




// ":" 기준으로 전까지 단어로 인식