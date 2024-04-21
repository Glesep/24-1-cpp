#include <iostream>
using namespace std;

int main() 
{
    int N, num;
    cin >> N;                           // 정수 개수
    
    int smallest = -1;

    for (int i = 0; i < N; i++)
    {
        cin >> num;                     // 정수 입력
        
        if (num >= 0 && (smallest == -1 || num < smallest)) {
            smallest = num;
        }
    }

    cout << smallest << endl;

    return 0;
}