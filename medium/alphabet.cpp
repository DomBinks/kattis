#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Get the string
    string inp;
    cin >> inp;

    // Convert the string to a vector of characters
    vector<char> str;
    for(int i = 0; i < inp.size(); i++)
    {
        str.push_back(inp[i]);
    }

    // Stores the length of the longest subsequence using the characters up to
    // and including the index
    vector<int> table(str.size());

    table[0] = 1; // Using the first character can get length 1

    for(int i = 1; i < str.size(); i++)
    {
        table[i] = 1; // At least 1 by using just character at index i
                      
        //For each character in the string to i
        for(int j = 0; j < i; j++)
        {
            // If the character at index i is greater than this character,
            // and using the characters to this character can generate a sequence
            // that with the character at index i is longer than the current
            // maximum length for characters to i
            if(str[i] > str[j] && table[i] < table[j] + 1)
            {
                // Update the longest subsequence
                table[i] = table[j] + 1;
            }
        }
    }

    // Get the maximum length from the table
    int maxLen = *max_element(table.begin(), table.end());

    // Subtract the length from 26 to find the number of extra letters to add
    cout << (26 - maxLen) << endl;

    return 0;
}
