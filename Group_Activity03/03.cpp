#include <iostream>
#include <string>
using namespace std;
string &concat(string str1, string str2) {
    string combined = str1 + str2;
    return combined;
}
int main() {
    string first = "How fun";
    string second = " is C++ !";
    string merged = concat(first, second);
    cout << merged << endl;
    return 0;
}