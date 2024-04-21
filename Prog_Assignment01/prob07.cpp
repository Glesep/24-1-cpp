#include <iostream>
using namespace std;
//첫번째가 이르면 -1, 두번째가 이르면 1, 똑같으면 0
int main() 
{
    int date_1[3], date_2[3];

    // 첫 번째 날짜 입력
    for (int i = 0; i < 3; i++)
    {
        cin >> date_1[i];
    }
    // 두 번째 날짜 입력
    for (int i = 0; i < 3; i++)
    {
        cin >> date_2[i];
    }

    // 년 같을 때,
    if (date_1[0] == date_2[0])                                             
    {
        // 년, 월 같을 떄,
        if (date_1[1] == date_2[1])                                         
        {
            if (date_1[2] == date_2[2])
                cout << 0 << endl;
            if (date_1[2] > date_2[2])
                cout << 1 << endl;
            if (date_1[2] < date_2[2])
                cout << -1 << endl;
        }
        // 월 다를 떄
        if (date_1[1] > date_2[1])
            cout << 1 << endl;
        if (date_1[1] < date_2[1])       
            cout << -1 << endl;                                        
    }
    // 년 다를 때
    if (date_1[0] > date_2[0])
        cout << 1 << endl;
    if (date_1[0] < date_2[0])
        cout << -1 << endl;

    return 0;
}

// #include <iostream>
// using namespace std;

// int main() {
//     int y1, m1, d1, y2, m2, d2;
//     cin >> y1 >> m1 >> d1 >> y2 >> m2 >> d2;
//     if (y1<y2 || y1==y2 && m1<m2 || y1==y2 && m1==m2 && d1<d2)
//         cout << -1;
//     // else 기능 잘 사용하기
//     else if (y1==y2 && m1==m2 && d1==d2)
//         cout << 0;
//     else
//         cout << 1;
//     return 0;
// }
