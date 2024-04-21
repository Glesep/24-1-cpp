#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    vector<int> num;
    while(1) {
        cin >> n;
        if (n == -1)
            break;
        
        if (num.size() != 0) {
            bool duplicate = false;
            for (int i : num) {
                if (n == i) {
                    cout << "duplicate" << endl;
                    duplicate = true;
                    break;
                }
            }
            if (duplicate == true)
                continue;

            else {
                auto it = num.begin();
                for (; it < num.end(); it++) {
                    if (*it > n) {
                        num.insert(it, n);
                        break;
                    }
                }
                if (it == num.end()) {
                    num.push_back(n);
                }
            }        
        }

        else {
            num.push_back(n);
        }

        for (int i : num) {
            cout << i << " ";
        }
        cout << endl;
        
        
        
    }
    return 0;
}