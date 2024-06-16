#include <iostream>
using namespace std;

class myClass {
    int pra = 5;
public:
    int pub = 10;
    void set_pr(int x) { pra = x; }
    void set_pu(int x) { pub = x; }
};


int main() {
    myClass m;
    int a, b;
    a = m.pra;
    b = m.pub;
    m.set_pr(100);
    m.set_pu(200);

    return 0;
}

/*
접근 지정자를 설정하지 않으면 private으로 지정된다.
*/
