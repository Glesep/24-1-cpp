#include <iostream>
using namespace std;

int main() {
    int s, t;
    cin >> s >> t;
    int cnt1 = 0, cnt2 = 0, cnt3 = 0;

    for (int i = s; i <= t; i++) {
        // 조건을 조심할 것
        if (i % 2 == 0)
            cnt1++;
        if (i % 3 == 0)
            cnt2++;
        if (i % 2 != 0 && i % 3 != 0)
            cnt3++;
    }
    cout << "The results are " << cnt1 << ", " << cnt2 << ", and " << cnt3 << endl; 
    return 0;
}