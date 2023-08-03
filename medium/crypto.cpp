#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Get the number
    int n;
    cin >> n;

    int bigNum = 0; // Number seen the most times
    int bigSeen = 0; // Amount of times the most seen number has been seen

    int seen = 0; // Amount of times the current number has been seen

    // While the number is even
    while(n % 2 == 0)
    {
        seen++; // Increment the number of 2s seen
        n /= 2; // Divide by 2 to remove a factor of 2
    }
    
    // If 2 has been seen
    if(seen > bigSeen)
    {
        bigNum = 2; // Set the number seen the most times to 2
        bigSeen = seen; // Set the amount of times 2 has been seen
    }

    // n is now odd, so consider odd factors
    // Don't have to worry about non-primes as they're handled by their
    // prime factors earlier on
    for(int i = 3; i <= sqrt(n); i+= 2)
    {
        seen = 0; // Number of times i has been seen
        while(n % i == 0) // While a factor of i can be taken out
        {
            seen++; // Increment seen
            n /= i; // Remove this factor of i
        }

        // If i has been seen more times than any other prime
        if(seen > bigSeen)
        {
            bigNum = i; // Set the number seen the most times to i
            bigSeen = seen; // Set the amount of times i has been seen
        }
    }

    // If there is a prime factor left, and no other prime factors have been seen
    if(n > 2 && 1 > bigSeen)
    {
        bigNum = n; // Set the number seen the most times to n
        bigSeen = 1; // Set the amount of times n has been seen to 1
    }

    cout << bigNum << endl;

    return 0;
}
