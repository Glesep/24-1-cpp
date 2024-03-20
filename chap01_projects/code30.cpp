#include <iostream>
#include <string>
using namespace std;
const int MAX = 100;

int main()
{
    string words[MAX], str;                 // 단어 저장 
    int count[MAX] = {0};                   // 등장 빈도 저장
    int n, k =0;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> str;                         // 문자열 입력
        int j = 0;                          // 변수를 아래의 for문 바깥에서도 사용하기 위해 여기서 초기화 (변수의 스코프 확인)
        for ( ; j < k; j++)                 // j = 0부터 k까지 word[j]와 입력된 문자열끼리 검사 (이미 단어가 존재하는지 검사)
        {
            if (words[j] == str)
                break;
        }

        // 위의 for문 탈출의 경우의 수 검사
        if (j < k)                          // j가 k 보다 작을 때 == 이미 words 배열에 존재했을 때
            count[j]++;                     // j번째 count의 값을 올려줌

        else                                // 새로운 단어였을 때
        {
            words[k] = str;                 // words배열에 추가
            count[k++] = 1;                 // k번째 count의 값을 1 올리고 k의 값도 1 올림
        }
    }

    for (int i = 0; i < k; i++)
        cout << words[i] << " " << count[i] << endl;

    return 0;
}