#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Get number of items and the max price of 2 items
    int n, x;
    cin >> n >> x;

    vector<int> ns(n); // Stores the item prices

    // Get the items
    for(int & i : ns)
    {
        cin >> i;
    }

    // Sort the items by price
    sort(ns.begin(), ns.end());

    int out = 1; // Number of items that can be sold
                 
    // For each item from the 2nd item
    for(int i = 1; i < n; i++)
    {
        // If this and the previous item i.e. 2 most expensive items are less
        // than the max
        if(ns[i]+ns[i-1] <= x)
        {
            out++; // Increment the number of items that can be sold
        }
    }

    cout << out << endl;

    return 0;
}
