#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> num;
    int k;
    while(1) {
        cin >> k;
        if (k == -1)
            break;
        
        num.push_back(k);
    }
    int count = 0;
    for (auto it = num.begin(); it < num.end(); it++) {
        if (it == num.begin()) {
            if(*it <= *(it+1))
                count++;
        }
        else if (it == num.end()-1) {
            if (*(it-1) >= *it)
                count++;
        }
        else {
            if (*it <= *(it-1) && *it <= *(it+1))
                count++;
        }
    }
    cout << count << endl;
    return 0;
}