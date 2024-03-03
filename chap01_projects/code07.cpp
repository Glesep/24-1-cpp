// if, else if, else가 어떻게 동작하는지 제대로 알자!

#include <iostream>
using namespace std;

int main()
{
    int s, t;
    cin >> s >> t; // s, t는 바로 입력이 되므로 초기화가 됨

    // 아래의 세 정수는 입력을 받지 않으므로 자체적으로 초기화를 시켜줘야 함
    int cnt_2 = 0;
    int cnt_3 = 0;
    int cnt_else = 0;

    if (s <= t)
    {
        for (int i = s + 1; i < t; i++)
        {
            if (i % 2 == 0)
                cnt_2++;
            if (i % 3 == 0) // 주의! ** else if를 사용했을 때는 위의 if문이 제외된 상태이므로 6의 배수 등등의 값이 제외된 체로 나온다 **
                cnt_3++;
            if (i % 2 != 0 && i % 3 != 0)
                cnt_else++;
        }

        cout << "2의 배수의 개수: " << cnt_2 << endl;
        cout << "3의 배수의 개수: " << cnt_3 << endl;
        cout << "나머지 개수: " << cnt_else << endl;
    }

    else
    {
        for (int i = t + 1; i < s; i++)
        {
            if (i % 2 == 0)
                cnt_2++;
            if (i % 3 == 0) // 주의! ** else if를 사용했을 때는 위의 if문이 제외된 상태이므로 6의 배수 등등의 값이 제외된 체로 나온다 **
                cnt_3++;
            if (i % 2 != 0 && i % 3 != 0)
                cnt_else++;
        }

        cout << "2의 배수의 개수: " << cnt_2 << endl;
        cout << "3의 배수의 개수: " << cnt_3 << endl;
        cout << "나머지 개수: " << cnt_else << endl;
    }

    return 0;
}