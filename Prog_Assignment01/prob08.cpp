#include <iostream>
using namespace std;

int main()
{
    int a, b, c, d;

    cin >> a >> b >> c >> d;            // [a,b], [c,d]

    if (a < c)
    {
        if (b >= c)
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }

    if (a > c)
    {
        if (d >= a)
            cout << "Yes" << endl;
        else 
            cout << "No" << endl;
    }
    
    return 0;
}