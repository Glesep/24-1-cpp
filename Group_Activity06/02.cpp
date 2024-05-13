#include <iostream>
using namespace std;

// int *a()
// {
//     int x = 10;             // 함수 안에서 정의된 변수의 주소를 가져오면 안됨
//     return &x;
// }

// int *b()
// {
//     int *px;
//     *px = 10;               // 포인터에 주소가 들어가지 않았는데 주소 안의 값을 불러오니 오류 발생
//     return px;              // px는 포인터이므로 옳바른 리턴
// }

int c()
{
    int *px;
    px = new int;
    *px = 10;
    return *px;             // 동적 할당된 값을 리턴하지만 함수가 끝난 뒤에 px 포인터가 없어지므로 Garbage 생성됨
}

int *d()
{
    int *px;
    px = new int;
    *px = 10;
    return px;              // 포인터가 리턴되어 사용이 되므로 옳다.
}

int main()
{
    // cout << a() << endl;
    
    // cout << b() << endl;
    cout << c() << endl;
    cout << d() << endl;

    return 0;
}
