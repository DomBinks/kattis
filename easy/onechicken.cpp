#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    cout << "Dr. Chaz ";

    if(n <= m)
    {
        int c = m - n;
        cout << "will have ";

        if(c == 1)
        {
            cout << "1 piece ";
        }
        else
        {
            cout << c << " pieces ";
        }
        cout << "of chicken left over!" << endl;
    }
    else
    {
        int c = n - m;
        cout << "needs ";

        if(c == 1)
        {
            cout << "1 more piece " << endl;
        }
        else
        {
            cout << c << " more pieces ";
        }
        cout << "of chicken!" << endl;
    }

    return 0;
}
