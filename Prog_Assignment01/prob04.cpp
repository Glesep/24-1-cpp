#include <iostream>
using namespace std;

int main() 
{
    int a, b, c;
    cin >> a >> b >> c;
    int tmp = 0;            // 값 보관 위한 변수 tmp
    
    // 제일 큰 숫자 옮기기
    if (a > b)
    {
        tmp = a;
        a = b;
        b = tmp;            //tmp == a    
    }

    if (b > c)
    {
        tmp = b;
        b = c;
        c = tmp;            // tmp == b
    }

    // 제일 작은 숫자 옮기기
    if (a > b)
    {
        tmp = a;
        a = b;
        b = tmp;            //tmp == a    
    }

    cout << a <<" "<<  b <<" "<< c << endl;

    return 0;
}