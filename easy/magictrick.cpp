#include <iostream>
#include <cstring>
using namespace std;

int main()
{
    string in; // Input string
    cin >> in;

    // Array to track which letters have been seen
    int letters[26];
    for(int i = 0; i < 26; i++)
    {
        letters[i] = 0;
    }

    // Track if you can always guess correctly or not
    bool guess = true;

    // For each letter in the input string
    for(int i = 0; i < in.length(); i++)
    {
        // If the letter has already been seen
        if(letters[((char)in[i])-97] == 1)
        {
            // You can't always guess correctly
            guess = false;

            // Don't check any more letters as you already know the answer
            break;
        }
        // If the letter hasn't been seen yet
        else
        {
            // Mark the letter as seen
            letters[in[i]-97] = 1;
        }
    }

    cout << (guess ? 1 : 0) << endl;
    return 0;
}
