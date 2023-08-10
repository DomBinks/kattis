#include <bits/stdc++.h>
#include <cstring>

using namespace std;

int main()
{
    map<string, bool> seen; // Seen words

    // Get each word
    string word;
    while(cin >> word)
    {
        string w = word; // Store the unmodified word

        // Convert word to all lower case
        transform(word.begin(), word.end(), word.begin(), [](unsigned char c) {
                return tolower(c);
        });

        // If this word has been seen
        if(seen.count(word))
        {
            // Print a dot
            cout << ".";
        }
        // If this word hasn't been seen
        else
        {
            // Print the unmodified word
            cout << w;
            // Set this word to seen
            seen[word] = true;
        }

        cout << " ";
    }
    cout << endl;

    return 0;
}
