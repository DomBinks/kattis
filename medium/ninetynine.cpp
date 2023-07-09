#include <iostream>

using namespace std;

int main()
{
    cout << 2 << endl;
    int x;
    int c = 0;
    while(c < 100)
    {
        cin >> x;
        if(x >= 88)
        {
            break;
        }
        
        if(x % 2 == 0)
        {
            cout << x + 1 << endl; 
        }
        else
        {
            cout << x + 2 << endl;
        }

        c++;
    }
    while(c < 200)
    {
        if(x == 88 || x == 89)
        {
            cout << 90 << endl;
        }
        if(x == 91 || x == 92)
        {
            cout << 93 << endl;
        }
        if(x == 94 || x == 95)
        {
            cout << 96 << endl;
        }
        else if(x == 97 | x == 98)
        {
            cout << 99 << endl;
            break;
        }

        cin >> x;
        c++;
    }
    
    return 0;
}
