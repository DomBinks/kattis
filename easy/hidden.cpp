#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Get the password and the message
    string password, message;
    cin >> password >> message;

    // Stores the positions of every character in the password
    map<char, list<int>> position;

    // For each character in the password
    for(int i = 0; i < password.size(); i++)
    {
        char c = password[i]; // Get the character

        // Set the position of this character in the password
        position[c].push_back(i);
    }

    // Add a -1 to the end of the positions of every character to denote that
    // this character doesn't appear in the rest of the password
    for(pair<char, list<int>> p : position)
    {
        p.second.push_back(-1);
    }

    int p = -1; // Position of the previous character relative to the password
    for(char c : message)
    {
        // If this character isn't in the password
        if(position[c].empty())
        {
            // Go to the next character
            continue;
        }
        // If all the instances of this character in the password have been
        // used
        else if(position[c].front() == -1)
        {
            cout << "FAIL" << endl;
            return 0;
        }

        // If this character is in the password
        
        // Get the position in the password of this character
        int i = position[c].front();
        position[c].pop_front();

        // If this position isn't 1 on from the previously seen character
        if(i != p+1)
        {
            cout << "FAIL" << endl;
            return 0;
        }
        // If this position is 1 on from the previously seen character
        else
        {
            p++; // Increment the position of the previously seen character
        }
    }

    // If the position of the password reached isn't equal to the length
    // of the password
    if(p != password.size() - 1)
    {
        cout << "FAIL" << endl;
        return 0;
    }

    cout << "PASS" << endl;
    return 0;
}
