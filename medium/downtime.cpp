#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Get the number of requests and requests per server
    int n, k;
    cin >> n >> k;

    // Stores the times when request finishes in increasing order
    queue<int> remove; 
    int m = 0; // Stores the maximum number of servers needed so far

    // For each request
    while(n-- > 0)
    {
        // Get the request
        int r;
        cin >> r;

        // While there are requests that have finished by the time this
        // request comes in
        while(remove.size() > 0 && r >= remove.front())
        {
            // If the request has finished by the time this request comes in
            if(r >= remove.front())
            {
                // Remove that request from the list of current requests
                remove.pop();
            }
        }

        // Add this request to the current requests
        remove.push(r+1000);

        // Calculate the number of servers needed to process the current
        // number of requests
        int s = (remove.size() + k - 1) / k;
        // Update the maximum number of servers needed
        m = max(m, s);
    }

    // Print the maximum number of servers needed
    cout << m << endl;

    return 0;
}
