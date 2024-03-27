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
    bool found = false;
    // 단어를 찾았을 때
    for (int i = 0; i < line.size(); i++)
    {
        int index_word = line[i].find('\t');
        string wordNow = line[i].substr(0, index_word);
        if (str == wordNow)
        {
            cout << "Found:" << endl;
            cout << str << ": " << line[i].substr(index_word+1) << endl;
            found = true;
            break;
        } 
    }

    // 단어를 찾지 못했을 때
    if (!found)
    {
        int n = 0;
        int index_word = line[0].find('\t');
        // str의 바로 다음에 올 단어의 인덱스 찾기
        while(str > line[n].substr(0, index_word))
            n++;
        
        cout << "Not found" << endl;
        // 바로 전
        cout << "- " << line[n-1].substr(0, line[n-1].find('\t')) << ": "
            << line[n-1].substr(line[n-1].find('\t')+1) << endl;
        // 바로 후
        cout << "+ " << line[n].substr(0, line[n].find('\t')) << ": "
            << line[n].substr(line[n].find('\t')+1) << endl;
    }

    // 접두사 체크.
    cout << endl;
    cout << "Results of prefix search:" << endl;
    for (int j = 0; j < line.size(); j++)
    {
        int index_word = line[j].find('\t');
        string word_check = line[j].substr(0, index_word);
            
        // 접두사가 아니라면
        int k = 0;
        for (; k < str.size(); k++)
        {
            if (word_check[k] != str[k])
            {
                break;
            }
        }
        // 접두사라면
        if (k == str.size())
        {
            cout << word_check << ": " << line[j].substr(index_word+1) << endl;
        }
    }
    infile.close();

    return 0;
}