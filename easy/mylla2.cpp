#include <bits/stdc++.h>

using namespace std;

int main()
{
    char board[3][3]; // Stores the board

    // Get the board
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            cin >> board[i][j];
        }
    }

    string win = ""; // The winner of the game
    
    // Loop over all verticles and horizontals
    for(int i = 0; i < 3; i++)
    {
        // Check horizontal
        if((board[i][0] == board[i][1] && board[i][1] == board[i][2]) && (board[i][0] != '_'))
        {
            win = board[i][0] == 'O' ? "Jebb" : "Neibb";
        }

        // Check vertical
        if((board[0][i] == board[1][i] && board[1][i] == board[2][i]) && (board[0][i] != '_'))
        {
            win = board[0][i] == 'O' ? "Jebb" : "Neibb";
        }
    }

    // Check leading diagonal
    if((board[0][0] == board[1][1] && board[1][1] == board[2][2]) && (board[0][0] != '_'))
    {
        win = board[0][0] == 'O' ? "Jebb" : "Neibb";
    }

    // Check other diagonal
    if((board[0][2] == board[1][1] && board[1][1] == board[2][0]) && (board[0][2] != '_'))
    {
        win = board[0][2] == 'O' ? "Jebb" : "Neibb";
    }

    // If it's a draw
    win = win == "" ? "Neibb" : win;

    cout << win << endl;

    return 0;
}
