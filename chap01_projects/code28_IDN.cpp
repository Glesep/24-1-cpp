#include <iostream>
#include <string>
using namespace std;

int main()
{
    string str;                                                     // 빈 스트링
    string str1 = "John Doe";
    string str2("Name-gu, Busan, Korea");
    string name = str1;                                             // string 타입 변수로도 초기화 가능하다.
    string address(str2);                                           // 위와 하는 일은 같다.
    cout << str << " " << str1 << " " << str2 << " "
         << name << " " << address << endl;

    string str3 = {"Hello World"};                                  // 중괄호로도 소괄호와 마찬가지의 행위를 할 수 있다.
    string str4{"Hello World"};
    string str5{str3};
    cout << str3 << " " << str4 << " " << str5 << endl;
        
    return 0;
}