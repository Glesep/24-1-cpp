#include <iostream>
using namespace std;

int main()
{
    int count = 0, limit = 100;
    for (int i=1; i<=limit; i++) {                                 

        for (int j=i+1; j<=limit; j++) {                           

            for (int k=j+1; k<=limit; k++) {                        

                if ((i + j + k) % 10 == 0)                      // i + j + k가 10의 배수가 되는 경우 count++                        
                    count++;
            }
        }   
    }
    cout << count << endl;
}



