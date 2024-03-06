#include <iostream>
using namespace std;

int main() 
{
    int value;                                                  //거래 금액
    cin >> value;
    int commission = 0;                                         // 수수료

    if (value <= 2500000)                                       // 이백오십만원 이하일 경우
    {
        commission = 30000 + 0.017 * value;                     // 수수료 계산
    }
    
    else if (value <= 6250000)                                  // 이백오십만원 초과 육백이십오만원 이하일 경우
    {
        commission = 56000 + 0.0066 * value;                    // 수수료 계산
    }
    
    else if (value <= 20000000)                                 // 육백이십오만원 초과 이천만원 이하일 경우
    {
        commission = 76000 + 0.0034 * value;                    // 수수료 계산
    }

    else                                                        // 이천만원 초과일 경우 (문제 조건 이상)
    {
        commission = 100000 + 0.0022 * value;                   // 수수료 계산
    }

    if (commission < 39000)                                     // 수수료가 삼만구천원 미만일 때...
        commission = 39000;

    cout << "Commission is " << commission << endl;
}