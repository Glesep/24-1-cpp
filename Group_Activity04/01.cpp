#include <iostream>
#include <vector>
// 아마 1, 2, 1, 1
using namespace std;
class A {
public:
    int data;
    A() {
        cout << "constructor1" << endl;
    }
    A(int a): data(a) {
        cout << "constructor2" << endl;
    }
};

int main() {
    // 벡터는 선언만 하면 변수가 생성이 되는게 아님
    // A x, y(10);
    // vector<A> vec_a;
    // 변수 2개를 생성
    // vector<A> vec_b(2);

    // 배열은 선언 즉시 변수가 생성
    // 사이즈가 3인 배열 만들기
    A arr[3];
    // 사이즈가 4인 배열에 각 값을 먼저 초기화 
    A arr2[4] = {1, 2, 3, 4};
    
    return 0;
}