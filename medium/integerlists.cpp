#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Fast IO
    // (Required to not get time limit exceeded)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // For each case
    int t;
    cin >> t;
    while(t-- > 0)
    {
        // Get the functions to perform
        string functions;
        cin >> functions;

        // Get the starting size of the list
        int sLen;
        cin >> sLen;

        vector<int> list(sLen); // Create a vector to store the list
        char rm; // Character used to store unused pieces of input strings

        // If the list doesn't contain any elements
        if(sLen == 0)
        {
            cin >> rm; // Get the '['
            cin >> rm; // Get the ']'
        }
        else
        {
            cin >> rm; // Get the '['

            // For each element
            for(int i = 0; i < sLen; i++)
            {
                cin >> list[i]; // Get the element and put it in the vector
                cin >> rm; // Get the ',' or ']'
            }
        }

        bool front = true; // Whether the vector is being accessed from the front
        bool error = false; // Whether an error has occurred

        // For each function in the function string
        for(char function : functions)
        {
            // If it's a reverse function
            if(function == 'R')
            {
                // Set the vector to be accessed from the opposite side
                front = !front;
            }
            // If it's a delete function
            else
            {
                // If the list is empty
                if(list.empty())
                {
                    // Can't delete anything so set error and break
                    error = true;
                    break;
                }

                // If the list is being accessed from the front
                if(front)
                {
                    // Delete the front element
                    list.erase(list.begin());
                }
                // If the list is being accessed from the back
                else
                {
                    // Delete the back element
                    list.erase(--list.end());
                }
            }
        }

        // If there wasn't an error
        if(!error)
        {
            // Print the list

            cout << "[";

            // If the list isn't empty, print its elements
            if(!list.empty())
            {
                // Print the first element
                // (if accessing from the front 0, otherwise the size - 1)
                cout << list[front ? 0 : list.size()-1];

                // For any other elements (2nd onwards)
                for(int i = 1; i < list.size(); i++)
                {
                    // (if accessing from the front i, otherwise the size - i - 1)
                    cout << "," << list[front ? i : list.size()-i-1];
                }
            }

            cout << "]" << endl;
        }
        // If there was an error
        else
        {
            cout << "error" << endl;
        }
    }

    return 0;
}
