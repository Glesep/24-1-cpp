#include <iostream>
using namespace std;

int main()
{
    int coef, expo_x, expo_y;
    cin >> coef >> expo_x >> expo_y;

    //계수
    if (coef == -1)
        cout << "-";
    else if (coef == 1)
        cout << "";
    else 
        cout << coef;

    // 차수가 둘 다 0일때
    if (expo_x == 0 && expo_y == 0)
    {
        if (coef == 1 || coef == -1)
            cout << 1;
        else 
            cout << "";
    }    
    
    // x의 차수가 1일 때
    if (expo_x == 1)
        cout << "x";
    // x의 차수가 1보다 클 때
    else if (expo_x > 1)
        cout << "x^" << expo_x;
    // y의 차수가 1일 때
    if (expo_y == 1)
        cout << "y";
    // y의 차수가 1보다 클 때
    else if (expo_y > 1)
        cout << "y^" << expo_y;
    
    return 0;
}