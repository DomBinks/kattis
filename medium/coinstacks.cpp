#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    // Get the number of stacks
    int n;
    cin >> n;

    int stacks[n+1]; // Stores the stacks
    int total = 0; // Stores the total number of coins
    int m = 0; // Stores the highest stack

    priority_queue<pair<int, int>> order; // Stores the stacks in order of size

    // For each stack
    for(int i = 1; i <= n; i++)
    {
        cin >> stacks[i]; // Get the stack
        total += stacks[i]; // Add it's coins to the total
        m = max(m, stacks[i]); // Update the highest stack

        // If the stack isn't empty
        if(stacks[i] > 0)
        {
            // Add it to the PQ of non-empty stacks using it's height
            order.push(make_pair(stacks[i], i));
        }
    }
    
    // If the total is odd or one stack contains over half the coins
    if(total % 2 != 0 || m > total / 2)
    {
        cout << "no" << endl;
    }
    else
    {
        cout << "yes" << endl;

        // While there are coins left to remove
        while(total > 0)
        {
            // Get the 2 biggest stacks
            int l = order.top().second;
            order.pop();
            int r = order.top().second;
            order.pop();

            // Print out the stacks being used this turn
            cout << l << " " << r << endl;

            // Decrement the stacks
            stacks[l]--;
            stacks[r]--;

            // Decrement the total by 2 i.e. once for each stack
            total -= 2;

            // Add the 2 biggest stacks back to the PQ
            order.push(make_pair(stacks[l], l));
            order.push(make_pair(stacks[r], r));
            // Have to remove and readd to ensure that you're always using the
            // biggest stacks
        }
    }

    return 0;
}
