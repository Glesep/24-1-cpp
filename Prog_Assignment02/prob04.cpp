#include <iostream>
#include <string>
#include <cctype>
using namespace std;

// 1. 문자를 읽은 후 숫자이면 part에 저장
// 2. 기호이면 part 변수의 문자열이 있을 경우 negative 변수에 따른 계산
// 3. 그 후 기호의 종류에 따라 negative 상태 변경
// 4. 마지막 숫자일 경우 negative 변수에 따른 추가 계산 
int main()
{
    string calculater;
    cin >> calculater;

    // 필요한 변수들
    string plus = "+", minus = "-", part ="";
    int sum = 0;
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
