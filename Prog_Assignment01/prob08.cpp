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

// #include <iostream>
// using namespace std;

// int main() {
//     int a, b, c, d;
//     cin >> a >> b >> c >> d;
    
//     // 안되는 최소조건만 생각하는 방법도 있다. (여집합)
//     if (b < c || d<a)
//         cout << "No" << endl;
//     else
//         cout << "Yes" << endl;

//     return 0;
// } 
