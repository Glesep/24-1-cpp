#include <iostream>
using namespace std;

int main() 
{
    int N, num;
    cin >> N;                           // 정수 개수
    
    int smallest = -1;

    for (int i = 0; i < N; i ++)
    {
        cin >> num;                     // 정수 입력
        
        if (num < 0)                    // num이 음의 정수라면
            continue;                   // 이번 반복을 종료 후 다음 반복 시작
        else if (smallest == -1)       
            smallest = num;             
        else if (num < smallest)
            smallest = num; 
    }

    cout << "RESULT : " << smallest << endl;

    return 0;
}