#include <iostream>
using namespace std;

int main() 
{
    int a[100];
    a[0] = 1;                                   // f_1 = 1
    a[1] = 1;                                   // f_2 = 1

    for (int i = 2; i<100; i++)                 
        a[i] = a[i-1] + a[i-2];                 // f_n = f_(n-1) + f_n-2)
}