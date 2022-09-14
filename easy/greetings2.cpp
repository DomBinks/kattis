#include <iostream>
#include <string>
using namespace std;

int main()
{
    string greeting;
    cin >> greeting;
    int e = (greeting.length() - 2) * 2;

    cout << 'h';
    for(int i = 0; i < e; i++)
    {
        cout << 'e';
    }
    cout << 'y' << endl;

    return 0;
}
