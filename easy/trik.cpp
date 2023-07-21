#include <iostream>

using namespace std;

int main()
{
    int cups[4] = {0, 1, 0, 0};
    
    char c;
    int temp;
    while(cin >> c)
    {
        if(c == 'A')
        {
            temp = cups[1];
            cups[1] = cups[2];
            cups[2] = temp;
        }
        else if(c == 'B')
        {
            temp = cups[2];
            cups[2] = cups[3];
            cups[3] = temp;
        }
        else
        {
            temp = cups[1];
            cups[1] = cups[3];
            cups[3] = temp;
        }
    }
    
    if(cups[1] == 1)
    {
        cout << 1 << endl;
    }
    if(cups[2] == 1)
    {
        cout << 2 << endl;
    }
    if(cups[3] == 1)
    {
        cout << 3 << endl;
    }
    
    return 0;
}