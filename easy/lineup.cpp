#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Get the number of names
    int n;
    cin >> n;

    // Get the first 2 names
    string a, b;
    cin >> a >> b;

    bool increasing = true; // Whether the names are increasing
    bool neither = false; // Whether there is no order

    // If the first name is after the second name alphabetically
    if(a > b)
    {
        // Set the names as decreasing
        increasing = false;
    }

    // For the rest of the names
    for(int i = 2; i < n; i++)
    {
        a = b; // Set a as the last seen name
        cin >> b; // Get the next name

        // If this name is after the previous name and the names should be
        // decreasing, or the name is before the previous name and the names
        // should be increasing
        if(increasing && b < a || (!increasing && a < b))
        {
            neither = true; // Set that neither is the case
        }
    }

    if(neither)
    {
        cout << "NEITHER" << endl;
    }
    else if(increasing)
    {
        cout << "INCREASING" << endl;
    }
    else
    {
        cout << "DECREASING" << endl;
    }

    return 0;
}
