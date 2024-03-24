#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// 1. 숫자냐 기호냐 판별
// 2. 숫자이면 iterator 개념과 비슷하게 index 저장
// 3. 문자이면 bool 이용해서 음수인지 양수인지 판별
int main()
{
    string calculater;
    cin >> calculater;
    string plus = "+", minus = "-";
    int sum = 0;
    string part ="";
    bool negative = false;
    for (int i = 0; i < calculater.length(); i++)
    {   
        // 숫자가 아니라면 (기호라면)
        if (!isdigit(calculater[i]))
        {
            // 앞에 숫자가 기록되어 있었으면 먼저 계산한다.
            if (!negative && part != "")
                sum += stoi(part);
            else if (negative && part != "")
                sum -= stoi(part);
            // 그 후 현재 발견된 기호를 갱신한다.
            if (calculater[i] == '-')                               // char는 '' 사용하기
                negative = true;
            else
                negative = false;
            
            // part를 초기화한다.
            part = "";
        }

        else
        {
            part += calculater[i];

            // 마지막 숫자일 때
            if (i == calculater.length()-1)
            {
                if (!negative)
                    sum += stoi(part);
                else
                    sum -= stoi(part);
            }
        }
    }

    cout << "The sum is " << sum << endl;
    return 0;
}
