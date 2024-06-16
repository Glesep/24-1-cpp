#include <iostream>
    
using namespace std;

int main()
{
    int a;
    char *x;
    x = (char *) &a;

    a = 512;
    x[0] = 1;
    x[1] = 2;

    cout << a << endl;
    
    return 0;
}

/*
int: 4 bytes
char: 1 bytes

a = 512일 떄,
a의 주소 -> a의 값(2진)
1000 -> 00000000
1001 -> 00000010
1002 -> 00000000
1003 -> 00000000

char *x = (char*) &a;
x[0] = 1000
x[1] = 1001
x[2] = 1002
x[3] = 1003

따라서 
x[0] = 1 = 00000001
x[1] = 2 = 00000010
이므로
1+512 = 513

*/
