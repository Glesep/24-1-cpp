// 답: 1362
#include <iostream>
using namespace std;
// 2x = 3y로 접근(if문에 집어놓기)
int main() {

    int cnt = 0;

    for (int x = 0; x <= 100; x++) {
        for (int y = 0; y <= 100; y++) {
            // 2/3 == 정수/정수 == 정수, 2.0/3 == 실수/정수 == 실수
            if (y <= (2.0/3)*x && y >= (1.0/3)*x && x*x + y*y <= 10000)
                cnt++;
        }
    }
    cout << cnt << endl;



    return 0;
}