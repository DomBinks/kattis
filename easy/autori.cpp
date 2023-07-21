#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    string s;
    cin >> s;
    cout << s[0];
    
    int i = 0;
    while(find(s.begin()+i, s.end(), '-') != s.end())
    {
        string::iterator it = find(s.begin()+i, s.end(), '-');
        cout << *(++it);
        i = it - s.begin();
    }
    cout << endl;
    
    return 0;
}