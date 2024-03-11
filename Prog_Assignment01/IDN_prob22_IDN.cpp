#include <iostream>
using namespace std;
const int MAX = 100;
// 극대 극소...
int main()
{
    int N; 
    cin >> N;
    int stop = 0;
    int stock[MAX];
    for (int i = 0; i < N; i++)
    {    
        cin >> stock[i];
        if (stock[i] == -1)
        {
            stop = i-1;             //수가 기록된 부분
            break;
        }
    }
    int min = stock[0], max = stock[0];
    int buy = 0, sell = 0, profit = 0;

    // min을 갱신하다 극솟값 지점이 나오면 구매, max를 갱신하다 극댓값 지점이 나오면 판매
    for (int i = 0; i <= stop; i++)      //stop까지가 인덱스
    {
        if (min > stock[i])
        {
            if (stock[i+1] == -1)       //값이 내려가는 도중에 끝났다면,
                break;

            min = stock[i];
            if (min < stock[i+1])       //극솟값일 떄,
            {
                buy = min;
                max = stock[i];
            }
        }

        else if (max < stock[i])
        {
            max = stock[i];
            if (max > stock[i+1])               // 극댓값이거나 끝났을 때
            {
                sell = max;
                profit += sell - buy;
                min = stock[i], buy = 0, sell = 0;        //초기화
            }
        }
    }

    cout << profit << endl;
    
    
}