#include <iostream>
#include <vector>
using namespace std;

int main() {
    vector<int> nums = {1, 2, 3, 2, 4, 5, 3, 6};
    // erase() 하면 주소가 저절로 조정됨
    // 2, 3, 2, 4, 5, 3, 6
    // 2, 2, 4, 5, 3, 6
    // 2, 2, 4, 3, 6,
    // auto: "auto는 초기화 값에 따라 알아서 데이터 타입을 정해주는 키워드"
    auto it = nums.begin();                         // 시작 벡터 주소 반환
    while(it != nums.end()) {
        if (*it % 2 != 0) 
            it = nums.erase(it);                    // iterator 다시 받아오는거 생각하기
        if (*it % 2 == 0)
            it++;
    }
    for (int num: nums) // "2 2 4 6"이 출력되어야 함
        cout << num << " ";
    cout << endl;
    return 0;
}
