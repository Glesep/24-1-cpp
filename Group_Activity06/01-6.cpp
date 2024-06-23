#include <iostream>
    
using namespace std;

int f(int x, int *py, int **ppz) {
    int y, z;
    **ppz += 1;
    z = **ppz;  // 5
    *py += 2;
    y = *py;    // 7
    x += 3;     // 7 = 4 + 3
    cout << x << " " << y << " " << z << endl;
    return x + y + z;

}

int main()
{
    int c, *b, **a;
    c = 4;
    b = &c;
    a = &b;

    cout << f(c, b, a);
    
    
    return 0;
}

/*
19
주소의 주소..
*/
