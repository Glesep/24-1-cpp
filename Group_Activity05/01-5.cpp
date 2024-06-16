#include <iostream>
    
using namespace std;

class A {
    int a;
public:
    void show() {
        a++;
        cout << "a: " << a << endl;
    }
    // void operator. () {
    //     cout << "operator . called\n";
    // }
};

int main()
{
    A a1, a2;
    
    return 0;
}

/*
., .*, ::, ?: (3항 연산자): 이러한 연산자들은 연산자 오버로딩을 할 수 없습니다.
*/
