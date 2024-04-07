#include <iostream>
using namespace std;
const int MAX = 100;

int main()
{
    int n;
    int data[MAX];
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> data[i];

    // 버블 정렬
    for (int i = n - 1; i > 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (data[j] > data[j+1])            // 맨 앞에서부터 시작해 최댓값을 data[i]로 몰아감
            {
                int tmp = data[j];
                data[j] = data[j+1];
                data[j+1] = tmp;
            }
        }
    }

    // 정렬 후 중복되지 않는 값을 앞으로 몰아준다.
    int k = 0;
    for (int i = 1; i < n; i++)                         // data[0] 값은 비교할 전 값이 없으니 무시 가능
    {
        if (data[i] != data[i-1])                       // 현재 인덱스의 값과 전의 인덱스의 값이 다르다면
            data[++k] = data[i];                        // k의 값을 1 늘리고 k가 가리키는 인덱스에 data[i] 값을 넣는다.
    }

    for (int i = 0; i <= k; i++)                        // k 까지 출력 (뒤에 남은 값은 무시)
        cout << data[i] << " ";
    cout << endl;

    return 0;
}