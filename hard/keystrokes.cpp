#include <iostream>
using namespace std;

int main()
{
    string s;
    cin >> s;
    int sLen = s.length();

    string output;
    int index = 0;

    for(int i = 0; i < sLen; i++)
    {
        if(s[i] == 'L')
        {
            index--;
        }
        else if(s[i] == 'R')
        {
            index++;
        }
        else if(s[i] == 'B')
        {
            output.erase(index-1,1);
            index--;
        }
        else
        {
            output.insert(output.begin()+index, s[i]);
            index++;
        }
    }

    cout << output << endl;
    return 0;
}
