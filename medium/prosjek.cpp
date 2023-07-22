#include <bits/stdc++.h>

using namespace std;

long gcd(long a, long b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    long t; // Stores the target number to get to 
    long p = 1; // Stores the target number of sheets to get to

    cin >> t; // Get the first digit

    char chr; // Get the decimal point
    cin >> chr;

    long q; // Get the digits after the decimal point
    cin >> q;

    // Move t up to make space for q after
    for(int x = q; x > 0; x /= 10)
    {
        t *= 10; // Increase the first digit part by a column
        p *= 10; // Increase the number of sheets needed by a column
    }

    t += q; // Add the part after the decimal point to the first part

    // Minimise t and p by dividing by the gcd
    long g = gcd(t, p);
    t /= g;
    p /= g;

    // Gives the real as a long integer

    vector<long> papers(6, 0); // Stores the amount of each paper number
    long count = 0; // Stores the number of sheets of paper used currently

    // For each paper number
    for(int i = 5; i > 0; i--)
    {
        // Produce as much of the target using this number as possible
        papers[i] = t / i;
        count += papers[i];
        t = t % i;
    }

    int i = 5; // Start at paper number 5
               
    // While we need extra sheets
    while(count < p)
    {
        // If we can get all the extra sheets by removing papers of number i
        if(count + papers[i] >= p)
        {
            // Convert enough papers of number i to papers of i-1 and 1
            papers[i] -= (p - count);
            papers[i-1] += (p - count);
            papers[1] += (p - count);
            count += (p - count);
        }
        // If we can't get all the extra sheets by removing papers of number i
        else
        {
            // Convert all papers of number i to papers of i-1 and 1
            papers[i-1] += papers[i];
            papers[1] += papers[i];
            count += papers[i];

            // Remove all the papers of number i
            papers[i] = 0;

            // Get the next i number
            i--;
        }
    }

    // Print the amounts of each number paper used
    cout << papers[1];
    for(int i = 2; i <= 5; i++)
    {
        cout << " " << papers[i];
    }
    cout << endl;

    return 0;
}
