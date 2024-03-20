#include <iostream>
#include <string>
using namespace std;

int main()
{
    string s;
    getline(cin, s);
    int sum = 0, start = 0;

    while(1) 
    {
        int fIndex = s.find("+", start);            // start index부터 "+" 기호를 찾는 메소드 
        if(fIndex == -1)                            // "+" 문자가 없을 때,
        {
            string part = s.substr(start);          // start 인덱스부터 끝까지 잘라내기
            if (part=="")                           // "+"로 끝나서 아무것도 잘려지지 않았을 때 (ex. 2+3+)
                break;
            sum += stoi(part);
            break;
        }
        int count = fIndex - start;                 // substr로 자를 문자 개수("+" 문자 이전 정수 개수)
        string part = s.substr(start, count);       // start 인덱스부터 count개의 문자를 substr하기 (인덱스위치의 문자도 포함)
        sum += stoi(part);                          // stoi : string to int -> 문자열을 정수값으로 변환
        start = fIndex + 1;
    }

    cout << "The sum is " << sum << endl;
    return 0;
}
