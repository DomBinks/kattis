#include <bits/stdc++.h>

using namespace std;

int main()
{
    long p = 1; // Stores the number of sheets needed
    long t; // Stores an integer that's a multiple of the input real

    cin >> t; // Get the first digit

    char chr; // Get the decimal point
    cin >> chr;

    long q; // Get the digits after the decimal point
    cin >> q;

    // While the first digit part is less than the part after the decimal
    while(t < q)
    {
        t *= 10; // Increase the first digit part by a column
        p *= 10; // Increase the number of sheets needed by a column
    }
    // If the decmial part is > 0
    if(q > 0)
    {
        t *= 10; // Increase the first digit part by a column
        p *= 10; // Increase the number of sheets needed by a column
    }

    t += q; // Add the part after the decimal point to the first part

    // Gives the real as a long integer

    vector<long> papers(6, 0); // Stores the amount of each paper number
    long count = 0; // Stores the number of sheets of paper used currently

    // For each paper number
    for(int i = 5; i > 0; i--)
    {
        papers[i] = t / i;
        count += papers[i];
        t = t % i;
    }

    int i = 5; // Start at paper number 5
               
    // While we need extra sheets
    while(count < p)
    {
        // If there are no papers left of this number
        if(papers[i] == 0)
        {
            // Move to papers of the next number
            i--;
        }
        else
        {
            // Add an extra sheet by using a sheet of number 1 less and a sheet
            // of number 1

            papers[i]--; // Remove a sheet of size i
            papers[i-1]++; // Add a sheet of the next size down
            papers[1]++; // Add a sheet of size 1
            count++; // Increment the sheets used by 1
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
