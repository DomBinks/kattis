#include <bits/stdc++.h>

using namespace std;

// Used to mark surrounding pixels as being part of this star
void mark(string **grid, int m, int n, int y, int x, string marker)
{
    // If there is a pixel above that's a star pixel
    if(y - 1 >= 0 && grid[y - 1][x] == "-")
    {
        grid[y-1][x] = marker; // Mark this pixel as being part of this star
        mark(grid, m, n, y-1, x, marker); // Mark the pixels around this pixel
    }
    // If there is a pixel below that's a star pixel
    if(y + 1 < m && grid[y + 1][x] == "-")
    {
        grid[y+1][x] = marker; // Mark this pixel as being part of this star
        mark(grid, m, n, y+1, x, marker); // Mark the pixels around this pixel
    }
    // If there is a pixel to the left that's a star pisel
    if(x - 1 >= 0 && grid[y][x - 1] == "-")
    {
        grid[y][x-1] = marker; // Mark this pixel as being part of this star
        mark(grid, m, n, y, x-1, marker); // Mark the pixels around this pixel
    }
    // If there is a pixel to the right that's a star pixel
    if(x + 1 < n && grid[y][x + 1] == "-")
    {
        grid[y][x+1] = marker; // Mark this pixel as being part of this star
        mark(grid, m, n, y, x+1, marker); // Mark the pixels around this pixel
    }
}

int main()
{
    int c = 1; // Tracks the current case
    int m, n; // Size of the grid

    // While we can get another grid
    while(cin >> m) // Get the rows
    {
        cin >> n; // Get the pixels per row
        
        string **grid = new string*[m]; // Create a 2D array to store the grid
        int marker = 0; // Used to track the number of stars

        // Get the grid
        for(int i = 0; i < m; i++)
        {
            grid[i] = new string[n];
            for(int j = 0; j < n; j++)
            {
                char x;
                cin >> x;
                grid[i][j] = x;
            }
        }

        // For each pixel in the grid
        for(int i = 0; i < m; i++)
        {
            for(int j = 0; j < n; j++)
            {
                if(grid[i][j] == "-") // If the pixel is part of a start
                {
                    mark(grid, m, n, i, j, to_string(marker)); // Mark this star's pixels
                    marker++; // Increment the stars marked
                }
            }
        }

        cout << "Case " << c << ": " << marker << endl;
        c++; // Increment the case
    }

    return 0;
}
