#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand((unsigned int) time(NULL));
    int T = 1;
    int result1 = 0, result2 = 0;

    while (T <= 1000000)
    {   
        for (int i = 0; i < 6; i++)
        {
            if (rand() % 6 + 1 == 1)
            {
                result1++;
                break;
            }    
        }
        
        int cnt = 0;                                // for문 안에서 정의하면 cnt == 2가 될 수 없음

        for (int i = 0; i < 12; i++)
        {
            if (rand() % 6 + 1 == 1)
                cnt++;

            if (cnt == 2)
            {
                result2++;
                break;
            }  
        }
        T++;
    }
    
    cout << "RESULT1 : " << result1 << " RESULT2 : " << result2 << endl;
    
    return 0;
}