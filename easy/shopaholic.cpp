#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n; // Number of items
    cin >> n;

    vector<int> p(n); // Costs of the items
                      
    // Get the cost of each item
    for(int &i : p)
    {
        cin >> i;
    }

    sort(p.begin(), p.end()); // Sort the items in ascending order
    
    // Optimal method is to split the prices into groups of 3 in descending
    // order and pick the smallest. 
    // You have to pick the 2 largest items of the group, so by picking the 2
    // largest possible means the discount is the largest possible as it is the
    // 3rd largest.

    long long total = 0; // Stores the total discount
    int i = n-3; // Index of the smallest of a group of 3
                 
    // While the index of the smallest is still in the list
    while(i >= 0)
    {
        total += p[i]; // Add the amount to the total
        i -= 3; // Move to the next index of 3
    }

    cout << total << endl;

    return 0;
}
