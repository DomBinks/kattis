#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<string,int> seen; // Stores the times a prefix has been seen
    
    // For each case
    int t;
    cin >> t;
    while(t-- > 0)
    {
        // Get the word
        string word;
        cin >> word;

        // If this word hasn't been seen as a prefix
        if(seen.count(word) == 0)
        {
            cout << 0 << endl;
        }
        // If this word has been seen as a prefix
        else
        {
            // Print the number of times this prefix has been seen
            cout << seen[word] << endl; 
        }

        string sub = ""; // Stores the current prefix
        // For each character in the word
        for(int i = 0; i < word.size(); i++)
        {
            sub.push_back(word[i]); // Add the word to the current prefix

            // If the current prefix hasn't been seen
            if(seen.count(sub) == 0)
            {
                // Set it as seen once
                seen[sub] = 1;
            }
            // If the current prefix has been seen
            else
            {
                // Increment the nuber of times seen
                seen[sub]++;
            }
        }
    }

    return 0;
}
