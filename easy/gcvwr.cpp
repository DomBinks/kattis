#include <iostream>
using namespace std;

int main()
{
    int g, t, n;
    int goods = 0;
    int item;
    cin >> g >> t >> n;
    for(int i = 0; i < n; i++)
    {
       cin >> item;
       goods += item;
    }

    cout << (g - t) * 0.9 - goods << endl;
    return 0;
}
