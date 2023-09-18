#include <bits/stdc++.h>

using namespace std;

// Used to mark the positions of the lines a queen can take
bool mark(int y, int x, char **board, int n)
{
    // Top left
    int d = 1;
    while(x-d >= 0 && y-d >= 0)
    {
        if(board[y-d][x-d] == 'Q')
        {
            return false;
        }
        else
        {
            board[y-d][x-d] = '-';
            d++;
        }
    }

    // Top
    d = 1;
    while(y-d >= 0)
    {
        if(board[y-d][x] == 'Q')
        {
            return false;
        }
        else
        {
            board[y-d][x] = '-';
            d++;
        }
    }

    // Top right
    d = 1;
    while(x+d < n && y-d >= 0)
    {
        if(board[y-d][x+d] == 'Q')
        {
            return false;
        }
        else
        {
            board[y-d][x+d] = '-';
            d++;
        }
    }

    // Right
    d = 1;
    while(x+d < n)
    {
        if(board[y][x+d] == 'Q')
        {
            return false;
        }
        else
        {
            board[y][x+d] = '-';
            d++;
        }
    }

    // Bottom right
    d = 1;
    while(x+d < n && y+d < n)
    {
        if(board[y+d][x+d] == 'Q')
        {
            return false;
        }
        else
        {
            board[y+d][x+d] = '-';
            d++;
        }
    }

    // Bottom
    d = 1;
    while(y+d < n)
    {
        if(board[y+d][x] == 'Q')
        {
            return false;
        }
        else
        {
            board[y+d][x] = '-';
            d++;
        }
    }

    // Bottom left
    d = 1;
    while(x-d >= 0 && y+d < n)
    {
        if(board[y+d][x-d] == 'Q')
        {
            return false;
        }
        else
        {
            board[y+d][x-d] = '-';
            d++;
        }
    }

    // Left
    d = 1;
    while(x-d >= 0)
    {
        if(board[y][x-d] == 'Q')
        {
            return false;
        }
        else
        {
            board[y][x-d] = '-';
            d++;
        }
    }

    return true;
}

int main()
{
    // Get the board size
    int n;
    cin >> n;

    // Create the board
    char **board = new char*[n];
    for(int i = 0; i < n; i++)
    {
        board[i] = new char[n];

        for(int j = 0; j < n; j++)
        {
            board[i][j] = '_';
        }
    }

    bool bad = false; // If the solution is a bad solution

    // For each queen
    for(int i = 0; i < n; i++)
    {
        // Get the position
        int x, y;
        cin >> x >> y;

        // Skip if the solution is already bad
        if(bad)
        {
            continue;
        }

        // Check if this position isn't a valid position for a queen
        if(board[y][x] == '-' || board[y][x] == 'Q')
        {
            bad = true; // Set this solution to be bad
            continue; // Skip marking the board
        }

        board[y][x] = 'Q'; // Put this queen onto the board

        // Mark the lines that the queen can take on the board
        // and check if a queen was found on one of the lines
        if(!mark(y, x, board, n))
        {
            bad = true; // Set this solution
        }
    }

    if(bad)
    {
        cout << "INCORRECT" << endl;
    }
    else
    {
        cout << "CORRECT" << endl;
    }

    return 0;
}
