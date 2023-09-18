#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Get the string
    string s;
    cin >> s;

    // Get the length
    int n = s.size();

    // Must be at least as small as the sqrt of the length for r <= c
    int r = floor(sqrt(n));
    // Decrement until r is a factor of n
    while(n % r != 0)
    {
        r--;
    }

    // c must be the other dimension to give n
    int c = n / r;

    // Create the matrix to store the characters
    char **mat = new char*[r];
    for(int i = 0; i < r; i++)
    {
        mat[i] = new char[c];
    }

    int x = 0; // Track which character should be inserted into the matrix next

    // Loop over the columns and rows
    for(int i = 0; i < c; i++)
    {
        for(int j = 0; j < r; j++)
        {
            // Insert the character into the matrix
            mat[j][i] = s[x];
            x++;
        }
    }

    // Loop over the rows and columns
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            // Print out the character
            cout << mat[i][j];
        }
    }
    cout << endl;

    return 0;
}
