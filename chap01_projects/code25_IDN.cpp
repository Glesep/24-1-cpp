// 정렬된 정수 사이에 새 값을 집어넣는다.
// vector로 한다면?
#include <iostream>
using namespace std;
const int MAX = 100;

int main()
{
    int n, t; 
    int data[MAX];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> t;
        int j = i - 1;                                          // 반복 당시 제일 끝 인덱스: i-1
        while (j >= 0 && data[j] > t)                           // 제일 끝 인덱스가 0보다 크거나 같고 입력한 값이 현재 data[j] == data[i-1]보다 작을 때,
        {
            data[j+1] = data[j];                                // data[j]의 뒤의 인덱스에 자기의 값을 대입하고 (뒤로 가고)
            j--;                                                // j의 값을 1 낮춘다. (기준점 조절)
        }
        data[j+1] = t;                                          // 조건을 만족하는 인덱스 j+1 위치에 t를 대입

        for (int k = 0; k <= i; k++)
            cout << data[k] << " ";
        cout << endl;
    }

    return 0;
}