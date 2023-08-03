#include <bits/stdc++.h>

using namespace std;

// Check if this image should be removed i.e. if there is an ad character in it
bool remove(char **grid, int sy, int sx, int ey, int ex)
{
    // For every cell in this image
    for(int i = sy+1; i < ey; i++)
    {
        for(int j = sx+1; j < ex; j++)
        {
            char c = grid[i][j]; // Get the character in the cell

            // If the character is an ad character
            if(!(
                ('A' <= c && c <= 'Z') || // Uppercase
                ('a' <= c && c <= 'z') || // Lowercase
                ('0' <= c && c <= '9') || // Number
                c == '?' || c == '!' || c == ',' || c == '.' || c == ' ' || c == '+'// Other
            ))
            {
                // Return true as this image should be removed
                return true;
            }

            // If this cell is the top left corner of another image
            if(grid[i][j+1] == '+' && grid[i+1][j] == '+' && grid[i][j] == '+')
            {
                // Store the x and y coordinates of the top left corner
                int y = i; 
                int x = j;

                int dy = y+1; // y coordinate of the bottom right corner

                // While the edge continues downwards
                while(dy < ey && grid[dy][x] == '+')
                {
                    dy++; // Increment the y coordinate
                }
                dy--; // Go back to the last coordinate that is a +

                int dx = x+1; // x coordinate of the bottom right corner
                              
                // While the edge continues to the right
                while(dx < ex && grid[dy][dx] == '+')
                {
                    dx++; // Increment the x coordinate
                }
                dx--; // Go back to the last coordinate that is a +


                // If this image should be removed
                if(remove(grid, y, x, dy, dx))
                {
                    // Loop over every cell in this area
                    for(int a = y; a <= dy; a++)
                    {
                        for(int b = x; b <= dx; b++)
                        {
                            // Set it to whitespace
                            grid[a][b] = ' ';
                        }
                    }
                }
            }
        }
    }

    // Return false as no ad characters were found, so this image shouldn't be
    // removed
    return false;
}

int main()
{
    // Get the height and width of the grid
    int h, w;
    cin >> h >> w;
    cin.ignore(256, '\n');

    // Get the grid
    char **grid = new char*[h];
    for(int i = 0; i < h; i++)
    {
        grid[i] = new char[w];
        string s;
        getline(cin, s);

        for(int j = 0; j < w; j++)
        {
            grid[i][j] = s[j];
        }
    }

    // For each cell in the grid
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            // If the cell isn't at the bottom or right edge
            if((i + 1) < h && (j + 1) < w)
            {
                // If the cell is the top left corner of an image
                if(grid[i][j+1] == '+' && grid[i+1][j] == '+' && grid[i][j] == '+')
                {
                    // Store the x and y coordinates of the top left corner
                    int y = i;
                    int x = j;

                    int dy = y+1; // y coordinate of the bottom right corner

                    // While the edge continues downwards
                    while(dy < h && grid[dy][x] == '+')
                    {
                        dy++; // Increment the y coordinate
                    }
                    dy--; // Go back to the last coordinate that is a +

                    int dx = x+1; // x coordinate of the bottom right corner

                    // While the edge continues to the right
                    while(dx < w && grid[dy][dx] == '+')
                    {
                        dx++; // Increment the x coordinate
                    }
                    dx--; // Go back to the last coordinate that is a +

                    // If this image should be removed
                    if(remove(grid, y, x, dy, dx))
                    {
                        // Loop over every cell in this area
                        for(int a = y; a <= dy; a++)
                        {
                            for(int b = x; b <= dx; b++)
                            {
                                // Set it to whitespace
                                grid[a][b] = ' ';
                            }
                        }
                    }
                }
            }
        }
    }

    // For every cell in the grid
    for(int i = 0; i < h; i++)
    {
        for(int j = 0; j < w; j++)
        {
            // Print the cell
            cout << grid[i][j];
        }
        cout << endl;
    }

    return 0;
}
