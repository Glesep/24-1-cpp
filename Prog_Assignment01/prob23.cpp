#include <iostream>
using namespace std;
const int MAX = 100;

int main()
{
    int data[MAX] = {0};
    int index = 0;
    int t;
    
    // 입력된 숫자 전체를 검사하여 t와 중복되었는지 판정
    // i == 입력해야되는 배열의 인덱스
    for (int i = 0; i < MAX; i++)
    {
        cin >> t;
        if (t == -1)
            break;
        
        // 중복 값이 나올 때
        int duplicate = 0;
        if (i > 0)
        {
            for (int n = i-1; n >= 0; n--)
            {
                if (data[n] == t)
                {
                    duplicate++;
                }
            }
        }

        if (duplicate == 1)
        {
            i--;
            cout << "duplicate" << endl;
            continue;
        }

        // 중복 값이 나오지 않았을 때
        // 선택 정렬 알고리즘
        int j = i-1;                                            // 반복 당시 제일 끝 인덱스: i-1    
          
        while (j >= 0 && data[j] > t)                           // 제일 끝 인덱스가 0보다 크거나 같고 data[j]가 t보다 클 때,
        {
            data[j+1] = data[j];                                // data[j]의 뒤의 인덱스에 자기의 값을 대입하고
            j--;                                                // j의 값을 1 낮춘다.
        }
        data[j+1] = t;                                          // 조건을 만족하는 인덱스 j+1 위치에 t를 대입

        for (int k = 0; k <= i; k++)
            cout << data[k] << " ";
        cout << endl;
    }

    return 0;
}