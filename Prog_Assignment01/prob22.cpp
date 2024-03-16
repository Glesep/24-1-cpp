#include <iostream>
using namespace std;
const int MAX = 100;
// 사면 무조건 판다.
// 극대 극소...


int main()
{
    int stock[MAX] = {0};
    int index_End = 0;
    // i == N개의 양의 정수를 받음
    for (int i = 0 ; i < MAX; i++)
    {
        cin >> stock[i];
        
        // -1이 입력되면 입력을 끝냄
        if (stock[i] == -1)
        {
            index_End = i-1;
            break;
        }
            
    }

    // 처음 값은 무조건 산다.
    int buy = stock[0];
    // 산 값 기준으로 값이 늘어날 때 sell을 갱신한다.
    int sell = stock[0];
    // 이익을 나타내는 변수 profit
    int profit = 0;
    for (int i = 1; i <= index_End; i++)
    {   
        // 현재 주식 가격이 하루 전의 주식 가격보다 높을 경우
        if (stock[i] > stock[i-1])
        {
            sell = stock[i];                    // 판매 기준을 갱신한다.
        }
        // 사야될 때, 주식이 계속 내린다면
        if (stock[i] < buy && buy == sell)
        {
            buy = stock[i];                     // 구매 기준, 판매 기준을 갱신한다.
            sell = stock[i];
        }
        
        // 현재 주식 가격이 하루 전의 주식 가격보다 낮을 경우 (sell != buy일 떄)
        if ((stock[i] < stock[i-1] || stock[i+1] == -1) && sell != buy)
        {
            // 이윤을 계산한다.
            profit += (sell - buy);

            // buy와 sell 값을 현재 값으로 초기화한다.
            buy = stock[i];
            sell = stock[i];

        }
    }
    cout << profit << endl;
    
    return 0;
}




