#include <iostream>
using namespace std;
const int MAX = 100;

int main()
{
    int data[MAX] = {0};
    int index = 0;
    int t;
    for (int i = 0; ; i++)
    {
        cin >> t;
        int stop = 0;
        //프로그램 종료
        if (t == -1)
            break;

        //반복되는지 확인
        for (int k = 0; k < i; i++)
        {
            if (data[i] == t)
            {
                cout << "duplicate" << endl;
                stop++;
                break;
            }
        }
        if (stop > 0)
        {
            i--;
            continue;
        }

        // 반복이 안되면 정렬
        int j = i - 1;
        
        while (j >= 0 && data[j] > t)                           // 제일 끝 인덱스가 0보다 크거나 같고 data[j]가 t보다 클 때,
        {   
            data[j+1] = data[j];                                // data[j]의 뒤의 인덱스에 자기의 값을 대입하고
            j--;                                                // j의 값을 1 낮춘다.
        }
    
        data[j+1] = t;
        for (int k = 0; k <= i; k++)
            cout << data[k] << " ";
        cout << endl;
    }

    return 0;
}