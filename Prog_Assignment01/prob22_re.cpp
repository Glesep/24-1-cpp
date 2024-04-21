#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    vector<int> stock;
    while(1) {
        cin >> N;
        if (N == -1)
            break;
        stock.push_back(N);
    }

    int gain = 0, total_gain = 0;

    for (auto it = stock.begin()+1; it < stock.end(); it++) {
        if (*(it-1) <= *it) {
            gain += *it - *(it-1); 
        }
        else {
            total_gain += gain;
            gain = 0;
        }
    }

    cout << total_gain + gain << endl;
    return 0;
}