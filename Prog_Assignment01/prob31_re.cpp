#include <iostream>
using namespace std;

int main() {
    int num;
    int flag[14] = {0};
    for (int i = 0 ; i < 7; i++) {
        cin >> num;
        flag[num] = 1;
    }

    int cnt = 0;
    for (int i = 1; i < 14; i++) {
        if (flag[i])
            cnt++;
        else
            cnt = 0;
    
        if (cnt == 5) {
            cout << "YES" << endl;
            // 프로그램 끝내기
            return 0;
        }
    }
    cout << "NO" << endl;

    return 0;
}