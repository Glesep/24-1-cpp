#include <iostream>
    
using namespace std;

void fun(int *a) {
    a = new int(4);
}

int main()
{
    int *p;
    fun(p);
    *p = 6;
    cout << *p;
    
    return 0;
}

/*
** Call by value **
p 변수에는 아무런 주소값이 없다.
*/
