#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int num[n];
    int sum = 0;
    double SD = 0, average = 0, deviation = 0, sum_dev= 0;                         // 표준편차, 평균 정의

    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
        sum += num[i];
    }
    average = (double)sum / n;
    
    for (int i = 0; i < n; i++)
    {
        deviation = num[i] - average;
        sum_dev += deviation * deviation;
    }

    SD = sqrt(sum_dev / n);

    cout << average << " " << SD << endl;

    return 0;
}