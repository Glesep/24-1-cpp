#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;                                                                  // 벡터 생성

    v.push_back(1);                                                                 // push_back(): 벡터의 맨 뒤에 새로운 원소를 삽입
    v.push_back(2);
    v.push_back(3);

    int s = v.size();                                                               // 벡터의 크기를 알려줌
    cout << s << endl;
        
    cout << v[0] << " " << v.at(1) << " " << v[2] << endl;                          // 벡터의 원소들을 읽는 방법


    // 존재하지 않는 원소에 대한 읽기 / 쓰기
    cout << v[3] << " " << v[4] << endl;                                            // 오류가 발생하지 않을 수 있지만 운이 좋은 것이고 원래 그렇게 하면 안됨    
    v[3] = 100;

    
    // 벡터 초기화
    vector<int> v2 = {1,2,3,4};                                                     // 1,2,3,4를 원소로 가지는 벡터 생성
    vector<int> v3{1,2,3,4};
    // vector<int> v3 = (3,4);                                                      // 오류 발생
    vector<int> v5(3,4);                                                            // 값을 4로 가지는 원소 3개를 만듦 - 혼자 다르네!

    // 벡터 복사 (배열에서는 허용되지 않는다.)
    vector<int> v6(v2);
    vector<int> v7{v2};
    vector<int> v8 = v2;

    v2[0] = 100;




}