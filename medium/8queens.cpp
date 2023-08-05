#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<pair<int, int>, bool> seen; // Stores the cells seen by a queen
    bool invalid = false; // If the board is invalid
    int queens = 0; // Number of queens seen

    // For each cell
    for(int i = 0; i < 8; i++)
    {
        for(int j = 0; j < 8; j++)
        {
            // Get the character
            char c;
            cin >> c;

            // If it's a queen
            if(c == '*')
            {
                queens++; // Increment the number of queens seen
            }

            // If it's a queen and the board isn't invalid yet
            if(c == '*' and !invalid)
            {
                // If the cell the queen is in has already been seen by a queen
                if(seen.count(make_pair(i, j)) > 0)
                {
                    invalid = true; // Set the board as invalid
                }
                else
                {
                    // Add all the cells in the vertical and horizontal lines
                    for(int k = 0; k < 8; k++)
                    {
                        seen[make_pair(k, j)] = true; // Vertical
                        seen[make_pair(i, k)] = true; // Horizontal
                    }

                    // Add all the cells top left
                    int di = i-1;
                    int dj = j-1;
                    while(di >= 0 && dj >= 0)
                    {
                        seen[make_pair(di,dj)] = true; 
                        di--;
                        dj--;
                    }

                    // Add all the cells bottom right
                    di = i+1;
                    dj = j+1;
                    while(di < 8 && dj < 8)
                    {
                        seen[make_pair(di,dj)] = true; 
                        di++;
                        dj++;
                    }

                    // Add all cells bottom left
                    di = i+1;
                    dj = j-1;
                    while(di < 8 && dj >= 0)
                    {
                        seen[make_pair(di,dj)] = true;
                        di++;
                        dj--;
                    }

                    // Add all cells top right
                    di = i-1;
                    dj = j+1;
                    while(di >= 0 && dj < 8)
                    {
                        seen[make_pair(di,dj)] = true;
                        di--;
                        dj++;
                    }
                }
            }
        }
    }

    cout << ((invalid || queens != 8) ? "invalid" : "valid") << endl;

    return 0;
}
