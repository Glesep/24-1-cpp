#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX = 1000;

int main()
{
    ifstream infile("example.txt");                                     // input34.txt 파일을 읽어서 infile이라는 객체에 넣는다.

    string lines[MAX];
    string line;
    int n = 0;

    while (getline(infile, line))                                       // 파일로부터 한 라인을 읽는다. 파일의 끝에 도달하면 false가 된다.
        lines[n++] = line;                                              // 공백도 읽어들임, 마지막 공백 라인은 \n이 잆으므로 읽어지지 않는다.                                  
    
    infile.close();

    // bubble sort
    for (int i = n-1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (lines[j].length() > lines[j+1].length())                // 큰 값을 오른쪽으로 계속 몰고 감                     
            {
                string tmp = lines[j];
                lines[j] = lines[j+1];
                lines[j+1] = tmp;
            }
        }
    }

    for (int i = 0; i < n; i++)
        cout << lines[i] << endl;

    return 0;
}