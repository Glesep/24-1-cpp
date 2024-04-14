#include <iostream>
#include <string>
using namespace std;
string &concat(string str1, string str2, string& combined) {
    combined = str1 + str2;
    return combined;
}
int main() {
    string first = "How fun";
    string second = " is C++ !";
    string combined = "";
    // 참조 딱지 붙여주면 같은 변수가 된다 생각하자
    string merged = concat(first, second, combined);
    cout << merged << endl;
    return 0;
}