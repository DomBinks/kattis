#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<string, string> dict;

    string line;
    
    while(true)
    {
        getline(cin, line);

        if(line == "")
        {
            break;
        }
        else
        {
            char *word;
            char *translation;

            word = strtok(const_cast<char*>(line.c_str()), " ");
            translation = strtok(nullptr, " ");

            dict[string(translation)] = string(word);
        }
    }

    cin.clear();
    string t;
    while(cin >> t)
    {
        if(dict.count(t) > 0)
            cout << dict[t] << endl;
        else
        {
            cout << "eh" << endl;
        }
    }

    return 0;
}
