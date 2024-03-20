#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string str;
    cin >> str; 

    for (int i = 0; i < str.length()/2; i++)                                            // 홀수일 때는 중간에 혼자 남은 문자는 비교할 필요가 없음
    {
        if (tolower(str.at(i)) != tolower(str.at(str.length()-i-1)))                    // 양쪽 비교, str.at(i) == str[i]
        {
            cout << "Not palindrome." << endl;
            return 0;                                                                   // 아닐 때, 프로그램 끝내버리기.
        }
    }
    cout << "Palindrome." << endl;
    return 0;
}