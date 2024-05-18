// 어떤 경우에 복사 생성자를 직접 만들어야 하는가?
#include <iostream>
#include <vector>
using namespace std;

class Foo {
public:
    int val;
    Foo() = default;
    Foo(int a): val(a) {}
};

class Bar {
public: 
    // 포인터, 포인터의 벡터, 혹은 포인터의 배열을 멤버로 가지는 경우 복사생성자 사용
    Foo *ptr = nullptr;
    vector <Foo *> vec;

    Bar() = default;

    //deep copy
    Bar(const Bar &t) {
        ptr = new Foo(*t.ptr);                  // Foo 클래스의 디폴트 복사생성자 사용
        for (auto &pt : t.vec) {
            vec.push_back(new Foo(*pt));
        }
    }
};

int main() {
    Bar a;
    a.ptr = new Foo(100);
    a.vec.push_back(new Foo(1));
    a.vec.push_back(new Foo(2));
    a.vec.push_back(new Foo(3));

    Bar b = a;                                  // 자동 생성된 복사생성자 생성 (얕은 복사)
    a.ptr->val = 200;
    a.vec[0]->val = 300;

    // b의 값도 200, 300
    cout << b.ptr->val << " " << b.vec[0]->val << endl;
    return 0;
}