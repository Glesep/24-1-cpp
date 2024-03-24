#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    vector<string> sentence{"how", "is", "programming"};
    // "how"와 "is" 사이에 "fun"을 삽입하고 있다.

    //First try
    sentence[1] = "fun";
    for (auto word: sentence)
        cout << word << " ";
    cout << endl;
    // 삽입된 것이 아니라 "is"가 "fun"으로 바뀌었다.

    // //Second try (오류 발생!)
    // sentence[1] = "is";
    // for (int i = 2; i >= 1; i--)
    //     sentence[i+1] = sentence[i];                                                    // sentence[3]까지 밀려나므로 매우 위험한 요소 존재
    // sentence[1] = "fun";
    // for (auto word: sentence)
    //     cout << word << " ";
    // cout << endl;
    // // 오류가 발생하진 않았지만 벡터 sentence의 size는 여전히 3이므로 "how fun is" 까지만 출력된다.

    //Third try
    // 굳이굳이 하는 법
    vector<string> sentence3{"how", "is", "programming"};
    sentence3.push_back("");
    for (int i = sentence3.size()-2; i >= 1; i--)
        sentence3.at(i+1) = sentence3.at(i);
    sentence3.at(1) = "fun";
    for (auto word: sentence3)
        cout << word << " ";
    cout << endl;

    return 0;
}
