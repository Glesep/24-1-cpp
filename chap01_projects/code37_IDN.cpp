#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> data{1, 2, 3, 4};

    int sum = 0;
    for (auto t: data)
        sum += t;
    cout << sum << endl;

    // arr[3] 부터 값이 없으므로 더하면 무의마한 값이 나온다.
    int arr[10];
    arr[0] = 1, arr[1] = 2, arr[2] = 3;

    int sum_arr = 0;
    for (int t:arr) 
        sum += t;
    cout << sum_arr << endl;

    return 0;
    
}