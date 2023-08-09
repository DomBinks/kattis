#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Get the number of books
    int n;
    cin >> n;

    // Get the books
    vector<int> books(n); // Put them in this vector
    for(int &i : books)
    {
        cin >> i;
    }

    // Sort the vector of books
    sort(books.begin(), books.end());

    int sum = 0; // Stores the sum of the prices
    
    // Sum the prices
    for(int i = 0; i < n; i++)
    {
        sum += books[i];
    }

    // Ignore the smallest prices that aren't in a group 3
    // Remove the smallest price from each group of 3 in increasing order
    // (Provides the highest discount as any other configuration of books
    // results in discounts on books of lower prices)
    for(int i = (n % 3); i < n; i += 3)
    {
        sum -= books[i];
    }

    cout << sum << endl;

    return 0;
}
