#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    vector<int> num;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int number;
        cin >> number;
        num.push_back(number);
    }

    sort(num.begin(), num.end());

    
    auto it = num.begin();
    while(it < num.end())
    {
        if (*it != *(it+1) || it+1 == num.end())
            it++;
        else if (*it == *(it+1))                                // 조건문을 이거 먼저 놔두면 마지막에 이 코드에 접근이 됨!!!
            num.erase(it+1);
        
    }
    
    cout << num.size() << ": ";
    for (int number: num)
        cout << number << " ";
    cout << endl;
    return 0;
}