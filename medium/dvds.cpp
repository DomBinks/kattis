#include <bits/stdc++.h>

using namespace std;

int main()
{
    int t; // Get the number of cases
    cin >> t;

    // For each case
    while(t-- > 0)
    {
        int n; // Get the numder of dvds
        cin >> n;

        int l = 0; // Last dvd number in the increasing order
        int c = 0; // Number of dvds out of order

        // For each dvd
        for(int i = 0; i < n; i++)
        {
            int x; // Get the dvd number
            cin >> x;

            // If the number doesn't continue from the last dvd number in the
            // increasing order
            if(x != l+1)
            {
                c++; // Increment the number out of order
            }
            // If the number continues from the last dvd number in the
            // increasing order
            else
            {
                l = x; // Update the last dvd number in the increasing order
            }
        }

        // Output the number of dvds out of order, as this represents the
        // minimal number of operations to sort the stack
        cout << c << endl;
    }

    return 0;
}
