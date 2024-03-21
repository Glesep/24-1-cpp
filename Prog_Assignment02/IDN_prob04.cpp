#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// 음수 양수 bool로 표현
int main()
{
    string s;
    getline(cin, s);
    int sum = 0, start = 0;
    bool negative = false;

    if (!isalnum(s[0]))
        negative = true;

    while(1) 
    {   
        if (negative)
            start++;

        int fPlusIndex = s.find("+", start);                // start index부터 "+" 기호를 찾는 메소드 
        int fMinusIndex = s.find("-", start);               // start index부터 "+" 기호를 찾는 메소드



        if(fPlusIndex == -1 && fMinusIndex == -1)           // "+", "-" 문자가 없을 때,
        {
            // 덧셈
            if (!negative)
            {
                string part = s.substr(start);              // start 인덱스부터 끝까지 잘라내기
                if (part=="")                               // "+"로 끝나서 아무것도 잘려지지 않았을 때 (ex. 2+3+)
                    break;
                sum += stoi(part);
                break;
            }
            // 뻴셈
            else
            {
                string part = s.substr(start);              // start 인덱스부터 끝까지 잘라내기
                if (part=="")                               // "+"로 끝나서 아무것도 잘려지지 않았을 때 (ex. 2+3+)
                    break;
                sum -= stoi(part);
                break;
            }
            
        }
        // 덧셈
        if (!negative)
        {
            if (fMinusIndex < fPlusIndex)                       // "-" 가 더 빨리 나올 때,
            {
                negative = true;
                
            }    
        
            else if (fMinusIndex > fPlusIndex)                  // "+" 가 더 빨리 나올 떄,
                negative = false;

            int count = fPlusIndex - start;                 // substr로 자를 문자 개수("+" 문자 이전 정수 개수)
            string part = s.substr(start, count);           // start 인덱스부터 count개의 문자를 substr하기 (인덱스위치의 문자도 포함)
            sum += stoi(part);                              // stoi : string to int -> 문자열을 정수값으로 변환

            
            
        }
        // 뻴셈
        else
        {
            int count = fMinusIndex - start;                // substr로 자를 문자 개수("-" 문자 이전 정수 개수)
            string part = s.substr(start, count);           // start 인덱스부터 count개의 문자를 substr하기 (인덱스위치의 문자도 포함)
            sum -= stoi(part);                              // stoi : string to int -> 문자열을 정수값으로 변환

            if (fMinusIndex < fPlusIndex)                       // "-" 가 더 빨리 나올 때,
                negative = true;
        
            else if (fMinusIndex > fPlusIndex)                  // "+" 가 더 빨리 나올 떄,
                negative = false;
           
        }
    }

    cout << "The sum is " << sum << endl;
    return 0;
}
