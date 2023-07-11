#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    
    for(int i = 0; i < s.length(); i++)
    {
        if(s[i] == 's')
        {
            if(i+1 < s.length() && s[i+1] == 's')
            {
                cout << "hiss" << endl;
                return 0;
            }
        }
    }
    
    cout << "no hiss" << endl;
    return 0;
}