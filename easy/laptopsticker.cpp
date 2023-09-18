#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Get the measurements
    int wc, hc, ws, hs;
    cin >> wc >> hc >> ws >> hs;

    // If the sticker is small enough
    if((wc >= ws + 2) && (hc >= hs + 2)) 
    {
        cout << "1" << endl;
    }
    // If the sticker is too big
    else
    {
        cout << "0" << endl;
    }

    return 0;
}
