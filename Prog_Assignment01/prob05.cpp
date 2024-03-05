#include <iostream>
using namespace std;

int main() 
{
    int N, num;
    cin >> N;                   // 정수 개수
    
    int smallest = -1;

    for (int i = 0; i < N; i ++)
    {
        cin >> num;
        
        if (num < 0)
            continue;
        else if (smallest == -1)
            smallest = num;   
        else if (num < smallest)
            smallest = num; 
    }

    cout << "RESULT : " << smallest << endl;
}