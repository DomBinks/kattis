#include <iostream>

using namespace std;

int main()
{
    // Get the input
    int n, s, m;
    cin >> n >> s >> m;

    // Get the board
    int board[n+1];
    for(int i = 1; i <= n; i++)
    {
        cin >> board[i];
    }

    int hops = 0; // Track the hops

    // Until an end condition is met
    while(true)
    {
        // If the goal has been reached
        if(board[s] == m)
        {
            cout << "magic" << endl;
            break;
        }

        // If this square has previously been visited
        if(board[s] == 0)
        {
            cout << "cycle" << endl;
            break;
        }

        int t = s; // Cache the square location
        s += board[s]; // Move to the next square
        hops++; // Update the hops
        board[t] = 0; // Set the square moved away from to 0 i.e. visited
        
        // If the frog has fallen of the left of the board
        if(s < 1)
        {
            cout << "left" << endl;
            break;
        }

        // If the frog has fallen of the right of the board
        if(s > n)
        {
            cout << "right" << endl;
            break;
        }
    }

    cout << hops << endl;

    return 0;
}
