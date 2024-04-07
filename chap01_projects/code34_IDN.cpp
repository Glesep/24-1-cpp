#include <iostream>
#include <fstream>
#include <string>

using namespace std;

const int MAX = 1000;

int main()
{
    ifstream infile("input34.txt");                                     // input34.txt 파일을 읽어서 infile이라는 객체에 넣는다.

    string lines[MAX];
    string line;
    int n = 0;

    while (getline(infile, line)) {
        if (line.length() > 0)                                          // 파일로부터 한 라인을 읽는다. 파일의 끝에 도달하면 false가 된다.
            lines[n++] = line;                                          // \n 앞에까지 getline함수는 읽어들이고 사용한 \n은 버린다. 따라서 마지막 빈 줄은 눈에는 보이지만 getline함수가 인식을 못한다.
    }                                                                    
    
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
 
    for (int i = 0; i < n; i++) {        
        cout << lines[i] << endl;
    }
    
    return 0;
}