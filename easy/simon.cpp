#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Get the number of cases
    int t;
    cin >> t;
    cin.ignore(256, '\n'); // Get cin ready for getline
    while(t-- > 0)
    {
        // Get the line
        string line;
        getline(cin, line);

        // If the first word is "simon"
        if(line.substr(0, line.find(" ")) == "simon")
        {
            line.erase(0, line.find(" ")+1); // Remove "simon "

            // If the second word is "says"
            if(line.substr(0, line.find(" ")) == "says")
            {
                // If there is a space afterwards, meaning there is another
                // word after "says"
                if(line.find(" ") < line.size())
                {
                    line.erase(0, line.find(" ")+1); // Remove "says "
                    cout << line << endl; // Print the remaining line
                }
                // Otherwise print a blank line
                else
                {
                    cout << endl;
                }
            }
            // Otherwise print a blank line
            else
            {
                cout << endl;
            }
        }
        // Otherwise print a blank line
        else
        {
            cout << endl;
        }
    }

    return 0;
}
