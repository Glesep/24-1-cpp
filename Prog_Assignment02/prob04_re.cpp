#include <iostream>
#include <string>
#include <cctype>
using namespace std;


int main() {
    string str;
    getline(cin, str);

    int pos = 0, sum = 0, start = 0;
    if (str[0] == '+' || str[0] == '-') {
        pos = 1;
    }
    while(1) {
        int index = str.find_first_of("+-", pos);

        // (string)find 함수가 안 찾아질 때는 -1 반환
        if (index == -1) {
            string substring = str.substr(start);
            if (substring == "")
                break;
            sum += stoi(substring);
            break;
            
        }
        // 문자열 자를 길이 구하기
        int count = index - start;

        string substring = str.substr(start, count);

        sum += stoi(substring);

        pos = index + 1;
        start = index;
    }
    cout << "The sum is " << sum << endl;
   
    return 0;
}