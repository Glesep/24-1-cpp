#include <iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    // 배열에 값 대입
    int data[n];
    for (int i = 0; i < n; i++)
        cin >> data[i];

    // 선택정렬 알고리즘
    int num = n;
    while (num>1)
    {
        int max = data[0];
        int max_index = 0;

        // data[k] 찾기
        for (int i = 0; i < num; i++)
        {
            if (data[i] > max)
            {
                max = data[i];                  
                max_index = i;
            }   
        }

        // 교환
        int tmp = 0;
        tmp = data[num-1];
        data[num-1] = data[max_index];
        data[max_index] = tmp;

        num--;
    }

    // 값 출력
    for (int i = 0; i < n; i++)
        cout << data[i] << " ";
    cout << endl;
    
    return 0;
}