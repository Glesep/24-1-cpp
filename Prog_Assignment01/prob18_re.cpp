#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;
    int count[10] = {0};

    for (int i = N; i > 0; i /= 10) {
        count[N%10]++;
        N /= 10;
    }
    
    for (int i : count)
    cout << i << " ";

    return 0;
}