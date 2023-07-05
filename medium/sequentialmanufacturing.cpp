#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    // Get number of machines and number of items
    long long n, p;
    cin >> n >> p;

    long long sum = 0; // Sum of all machine processing times
    long long big = 0; // Longest machine processing time

    // Get each processing time
    for(int i = 0; i < n; i++)
    {
        long long x;
        cin >> x;
        sum += x; // Add the time to the sum
        big = max(big, x); // Update the max if applicable
    }

    // Get each input area size (not used)
    for(int i = 0; i < n-1; i++)
    {
        long long x;
        cin >> x;
    }

    // The biggest processing time is the only bottleneck we need to worry about
    // As this time happens for each item to make, add this time an additional p-1 times
    long long out = sum + (p-1)*big;
    cout << out << endl;
    return 0;
}
