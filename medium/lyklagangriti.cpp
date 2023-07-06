#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
    // Get the string the user enters
    string password;
    cin >> password;

    list<char> output; // Stores the output password
    list<char>::iterator ptr = output.end(); // Tracks where in the output list we are

    string::iterator it = password.begin(); // Go to the start of the user string
    output.push_back(*it); // Add the first letter to the output as it's always a letter
    it++; // Go to the next letter

    // While there are letters of the input left
    while(it != password.end())
    {
        // If the cursor should move to the left
        if(*it == 'L')
        {
            ptr--; // Decrement the cursor pointer
        }
        // If the cursor should move to the right
        else if(*it == 'R')
        {
            ptr++; // Increment the cursor pointer
        }
        // If a character should be removed from the output
        else if (*it == 'B')
        {
            list<char>::iterator tmp = ptr; // Copy the pointer

            // Decrement the pointer to get to the character behind the cursor and remove it
            output.erase(--tmp);
        }
        // If the letter is a normal key
        else
        {
            // If the cursor is at the end
            if(ptr == output.end())
            {
                // At it to the back of the output
                output.push_back(*it);
            }
            // If the cursor is in the middle of the output
            else
            {
                // Insert it in front of the cursor
                // (implicitly increments ptr)
                output.insert(ptr, *it);
            }
        }

        // Get the next input letter
        it++;
    }

    // Print the characters in the output list
    for(char x : output)
    {
        cout << x;
    }
    cout << endl;

    return 0;
}
