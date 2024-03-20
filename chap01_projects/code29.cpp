#include <iostream>
#include <string>
using namespace std;

int main()
{
    string text;

    while(1) 
    {
        getline(cin, text);                                             // getline 함수는 cin으로부터 한 라인 전체를 읽어 text에 저장한다. 줄바꿈 문자(\n) 자체는 저장하지 않는다.
                                                                        // getline(cin, text, '\t');는 탭문자가 나올때까지 읽는다 (기본: 줄바꿈 문자(\n))
                                                                        
        if (text == "exit")                                             // 문자열끼리도 == 연산자 사용 가능
            break;
        
        cout << text << ":" << text.length() << endl;                   // 문자열의 길이 == .length()
    }
}