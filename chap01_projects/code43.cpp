#include <iostream>
#include <vector>
using namespace std;

// 벡터를 순환할 때, vec.begin과 vec.end()를 이용하여 vector의 범위를 정해준다.
int main()
{
    vector<int> vec{10, 8, 1, 5, 4, 6, 11, 2};
    vector<int>::iterator it = vec.begin();

    // it이 vec.end() == 마지막 원소의 다음 위치 가 아닐 때 반복
    while (it != vec.end())
    {
        if (*it % 2 == 0)
        {
            *it *= 2;
            it++;
        }
        else
            it = vec.erase(it);                                             // it은 삭제된 다음 원소를 가리킨다. 
    }

    for (auto it = vec.begin(); it != vec.end(); it++)
        cout << *it << " ";
    cout << endl;
    return 0;
}