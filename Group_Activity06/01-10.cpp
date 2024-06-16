#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> vec;
    vec.push_back(10);

    int *ptr = &vec[0];
    vec.push_back(20);
    vec[0] = 30;
    cout << *ptr << endl;
    
    return 0;
}

/*
vector 주소 가지고 난리치지말자
*/
