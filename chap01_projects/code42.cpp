#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<int> v;
    for (int i=0; i < 4; i++)
        v.push_back(i+1);


    vector<int>::iterator it;                       // iterator는 포인터 느낌
    it = v.begin();                                 // vector의 시작 iterator를 주는 begin() 함수

    it++;                                           // iterator의 증가(다음 칸으로 옮겨감)

    int n = *it;                                    // iterator를 이용한 원소 읽기, 쓰기
    cout << n << endl;                              // 2가 출력됨

    *it = n * 2;
    for (auto x: v)
        cout << x << " ";
    cout << endl;
// =========================================================================================================================
    v.insert(it, 100);                              // insert 후 it이라는 iterator는 무효화
    for (auto x: v)
        cout << x << " ";
    cout << endl;
    cout << *it << endl;                            // 의미 없는 값 출력
// ==========================================================================================================================
    it = v.begin();
    it += 2;                                        // 두 칸 전진

    it = v.insert(it, 200);                         // 새로운 값을 넣고, 이 insert가 반환하는 iterator를 it에 다시 받음
    for (auto x: v)
        cout << x << " ";
    cout << endl;
    cout << *it << endl;
// ===========================================================================================================================
    it = v.begin();
    it += 3;

    it = v.erase(it);                               // 새로운 값을 넣고, 이 insert가 반환하는 iterator를 it에 다시 받음                         
    for (auto x: v)
        cout << x << " ";
    cout << endl;
    cout << *it << endl;
    return 0;
}