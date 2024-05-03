#include <iostream>
#include <string>
#include <cctype>
using namespace std;

int main() {
    string line;
    while(1) {
        getline (cin, line);
        if (line == "exit")
            break;
            
        auto it = line.begin();
        while (it != line.end()) {
            // 현재 공백 && 첫 단어이거나 그 전이 공백일 경우
            if (isspace((*it)) && ((it == line.begin()) || isspace(*(it-1))))
                it = line.erase(it);
            else
                it++;
        }
        // it == line.end()일 떄,
        if (isspace(*(it-1)))
            line.erase(it-1);
        cout << line << ":" << line.length() << endl;
    }
    return 0;
}

// int main()
// {
//     string text;

//     while(1)
//     {   
//         getline(cin, text);
//         if (text == "exit")
//             break;

//         for (int i = 0; i < text.length(); i++)
//         {
//             // 맨 앞 공백 지우기
//             if (isspace(text[0]))
//             {
//                 text.erase(0,1);
//                 i--;
//             }
            
//             // 앞이 공백이고 뒤가 문자나 숫자가 아닌 경우
//             else if (isspace(text[i]) && !isalnum(text[i+1]))
//             {   
//                 text.erase(i,1);
//                 i--;
//             }

//             // 맨 뒤가 공백인 경우
//             else if (isspace(text.back()))
//             {
//                 text.erase(text.length()-1, 1);
//             }    
//         }

//         cout << text << ":" << text.length() << endl;
//     }

//     return 0;
// }



//int main() {
//    string line;
//
//    while(1) {
//        getline(cin, line);
//        if (line == "exit") break;
//        int k=0;
//        stringstream ss;
//        for (int i=0; i<line.length(); i++) {
//            if (!isspace(line[i]) || i>0 && !isspace(line[i-1]))
//                ss << line[i], k++;
//        }
//        if ()
//        ss << ":" << k;
//        cout << ss.str() << endl;
//    }
//
//    return 0;