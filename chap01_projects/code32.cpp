#include <iostream>
#include <string>
using namespace std;

const int MAX = 100;

int main()
{
    string words[MAX], pattern;
    int N;
    cin >> N;
    for (int i = 0; i < N; i++)
        cin >> words[i];
    cin >> pattern;

    for (int i = 0 ; i < N; i++)
    {
        int index = words[i].find(pattern);                                 // words[i].find(pattern): words[i] 안에 pattern이 속해 있으면 pattern이 시작하는 인덱스를 반환하는 메소드이다.

        if (index > -1)                                                     // pattern이 존재한다면,
            cout << words[i] << endl;                                       // word[i] 출력
    }
    return 0;
}