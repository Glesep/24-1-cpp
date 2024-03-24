#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

int main()
{
    vector<string> words;
    string word;

    while (1)
    {
        cin >> word;
        if (word == "exit")
            break;
        
        bool duplicate = false;
        for (int i = 0; i < words.size(); i++)
        {
            if (word == words[i])
            {
                duplicate = true;
                cout << "duplicate" << endl;
                break;
            }
        }

        if (!duplicate)
        {
            words.push_back(word);
            sort(words.begin(), words.end());

            for (int i = 0; i < words.size(); i++)
                cout << words[i] << " ";
            cout << endl; 
        }

    }

    return 0;
}