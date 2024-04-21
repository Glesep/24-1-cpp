#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int main() {
    // 난수 생성
    srand((unsigned int) time(NULL));
    int T = 1;
    int winStack1 = 0, winStack2 = 0;
    while (T <= 1000000) {
        int cnt1 = 0, cnt2 = 0;
        for (int i = 0; i < 6; i++) {
            if ((rand() % 6 + 1) == 1) {
                cnt1++;
                break;
            }
        }
        if (cnt1 >= 1)
            winStack1++;

        for (int i = 0; i < 12; i++) {
            if ((rand() % 6 + 1) == 1) {
                cnt2++;
            }
            if (cnt2 == 2)
                break;
        }
        if (cnt2 >= 2)
            winStack2++;
        
        T++;
    }

    cout << double(winStack1) / T << " " << double(winStack2) / T << endl; 

    return 0;
}