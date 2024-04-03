#include <iostream>
#include <string>
using namespace std;
// 이거 정리하기
string &concat(string str1, string str2) {
    string combined = str1 + str2;
    return combined;
}
int main() {
    string first = "How fun";
    string second = " is C++ !";
    string &str = second;
    
    string merged = str;
    cout << merged << endl;
    return 0;
}