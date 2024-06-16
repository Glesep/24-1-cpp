#include <iostream>
    
using namespace std;

void f(int *p, int *q) {
    p = q;
    *p = 2;
}

int i = 0, j = 1;

int main()
{
    f(&i, &j);
    cout << i << " " << j << endl;
    
    return 0;
}

/*
0 2

매개변수 타입 주의
*/
