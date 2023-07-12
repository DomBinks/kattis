#include <iostream>

using namespace std;

int main()
{
    while(true)
    {
        long long a, b;
        cin >> a;
        if(cin.eof())
            break;
        cin >> b;
        cout << (a > b ? a - b : b - a) << endl;
    }

    return 0;
}
