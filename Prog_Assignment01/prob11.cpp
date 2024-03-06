#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // 뒷자리부터 하나씩 출력함
    while (n > 0)
    {
        cout << n % 10;
        n /= 10; 
    }
    return 0;
}