#include <iostream>
#include <string>
#include <cctype>
using namespace std;


int main()
{
    string text;

    while(1)
    {   
        getline(cin, text);
        if (text == "exit")
            break;

        for (int i = 0; i < text.length(); i++)
        {
            // 맨 앞 공백 지우기
            if (isspace(text[0]))
            {
                text.erase(0,1);
                i--;
            }
            
            // 앞이 공백이고 뒤가 문자나 숫자가 아닌 경우
            else if (isspace(text[i]) && !isalnum(text[i+1]))
            {   
                text.erase(i,1);
                i--;
            }

            // 맨 뒤가 공백인 경우
            else if (isspace(text.back()))
            {
                text.erase(text.length()-1, 1);
            }    
        }

        cout << text << ":" << text.length() << endl;
    }

    return 0;
}