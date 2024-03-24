#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> data;
    int k;
    
    while(1)
    {
        cin >> k;

        if (k == -1)
            break;
        
        data.push_back(k);
    }
    // ===============================================================================================================
    // 내가 한 풀이: 버블정렬을 해서 앞에 두개 값을 불러온다.
    // int n = data.size()-1;
    // // 버블 정렬
    // for (int i = n; i > 0; i--)
    // {
    //     for (int j = 0; j < i; j++)
    //     {
    //         if (data[j] > data[j+1])            // 맨 앞에서부터 시작해 최댓값을 data[i]로 몰아감
    //         {
    //             int tmp = data[j];
    //             data[j] = data[j+1];
    //             data[j+1] = tmp;
    //         }
    //     }
    // }
    // ===============================================================================================================
    // 교수님 풀이
    int min = data[0], second_min = data[1];                // 초기값을 위치 상 정하고
    if (min > second_min)                                   // min > second_min일 때, 자리를 바꿔주기
    {
        min = data[1];  
        second_min = data[0];
    }
    for (int i = 2; i < data.size(); i++)
    {
        if (data[i] < min)
        {
            second_min = min;                               // 기존 min은 second_min으로 옮겨주고
            min = data[i];                                  // min에 data[i]의 값 넣어주기
        }
        else if (data[i] < second_min)          
            second_min = data[i];
    }

    cout << data[0] << " " << data[1] << endl;

    return 0;
}