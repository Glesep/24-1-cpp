#include <iostream>
#include <string>
using namespace std;

// 참조를 반환하는 함수를 만들 수 있다!
// 항상 매개변수의 타입을 맞춰서 넣어주자
string& concat(string &str1, string &str2) {
    str1 += str2;
    return str1;
}

int main() {
    string first = "Hello ";
    string second = "C++ ";
    string third = "programming";
    concat(concat(first, second), third);

    cout << first << endl;
    return 0;
}