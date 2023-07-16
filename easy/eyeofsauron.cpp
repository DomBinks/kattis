#include <iostream>

using namespace std;

int main()
{
    string s;
    cin >> s;
    
    int l = 0;
    int r = 0;
    int i = 0;
    while(s[i] != '(')
    {
        l++;
        i++;
    }
    i += 2;
    while(i < s.length())
    {
        r++;
        i++;
    }
    cout << l << " " << r << endl;
    
    cout << (l == r ? "correct" : "fix") << endl;
    
    return 0;
}
