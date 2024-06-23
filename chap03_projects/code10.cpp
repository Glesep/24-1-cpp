// 어떤 경우에 복사 생성자를 직접 만들어야 하는가?
#include <iostream>
#include <vector>
using namespace std;

class Foo {
public:
    int val;
    Foo() = default;
    Foo(int a): val(a) {}

    ~Foo() {
        cout << "Foo class destructor executed." << endl;
    }
};

class Bar {
public: 
    // 포인터, 포인터의 벡터, 혹은 포인터의 배열을 멤버로 가지는 경우 복사생성자 사용
    Foo *ptr = nullptr;
    vector <Foo *> vec;

    Bar() = default;
    Bar(Foo *p, vector<Foo *> v) : ptr(p), vec(v) {}
    //deep copy
    Bar(const Bar &t) {
        copy_members(t);
    }

    // 자신의 참조를 반환하면 = 연산자를 연속적으로 적용할 수 있다.
    // Bar x, y, z;
    // z = y = z;
    Bar &operator=(const Bar &t) {
        clearMembers();                         // **멤버들을 삭제해줌**
        copy_members(t);
        return *this;
    }

    ~Bar() {    // Bar 타입 안의 클래스 타입 멤버들을 안전하게 삭제
        clearMembers();
        cout << "Bar Class destructor executed." << endl;
    }

private:
    void clearMembers() {
        delete ptr;
        for (auto p : vec)
            delete p;
        // 벡터 내의 요소를 삭제 후 크기를 0으로 만듦
        vec.clear();
    }

    void copy_members(const Bar &t) {
        ptr = new Foo(*t.ptr);                  // Foo 클래스의 디폴트 복사생성자 사용
        for (auto &pt : t.vec) {
            vec.push_back(new Foo(*pt));
        }
    }
};

void func() {
    Foo *f = new Foo(100);
    vector<Foo *> v{new Foo(1), new Foo(2), new Foo(3)};
    Bar a(f, v);
}

int main() {
    func();
    return 0;
}