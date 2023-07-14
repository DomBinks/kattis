#include <iostream>
#include <map>
#include <algorithm>

using namespace std;

// Mark the cells that surround x,y as being in the same area if they are the
// same digit
void mark(int y, int x, int r, int c, string **grid, string digit, string area)
{
    // If there is a cell above
    if(y-1 >= 1)
    {
        // If the cell above is the same digit
        if(grid[y-1][x] == digit)
        {
            grid[y-1][x] = area; // Mark the cell
            mark(y-1, x, r, c, grid, digit, area); // Recursively mark adjacent cells
        }
    }
    
    // If there is a cell below
    if(y+1 <= r)
    {
        // If the cell below is the same digit
        if(grid[y+1][x] == digit)
        {
            grid[y+1][x] = area; // Mark the cell
            mark(y+1, x, r, c, grid, digit, area); // Recursively mark adjacent cells
        }
    }

    // If there is a cell to the left
    if(x-1 >= 1)
    {
        // If the cell to the left is the same digit
        if(grid[y][x-1] == digit)
        {
            grid[y][x-1] = area; // Mark the cell
            mark(y, x-1, r, c, grid, digit, area); // Recursively mark adjacent cells
        }
    }

    // If there is a cell to the right
    if(x+1 <= c)
    {
        // If the cell to the right is the same digit
        if(grid[y][x+1] == digit)
        {
            grid[y][x+1] = area; // Mark the cell
            mark(y, x+1, r, c, grid, digit, area); // Recursively mark adjacent cells
        }
    }

    return;
}

int main()
{
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Get number of rows and columns
    int r, c;
    cin >> r >> c;

    // Store the grid, representing each cell with a string
    string **grid = new string*[1001];

    // For each row
    for(int i = 1; i <= r; i++)
    {
        // Get the row
        string row;
        cin >> row;

        // Create an array of strings to store each cell in this row
        grid[i] = new string[1001];

        // For each character in the string i.e. a cell
        for(int j = 1; j <= c; j++)
        {
            // Convert the character to a string implicitly and put into the grid
            grid[i][j] = row[j-1];
        }
    }

    // Maps area strings to the original digit string
    map<string, string> areaToDigit;

    int area = 2; // Number that represents the next area that's found
    
    // For each row in the grid
    for(int i = 1; i <= r; i++)
    {
        // For each cell in the row
        for(int j = 1; j <= c; j++)
        {
            // If the cell isn't in an area yet i.e. still 0 or 1
            if(grid[i][j] == "0" || grid[i][j] == "1")
            {
                // Note the original digit
                string digit = grid[i][j];

                // Map this area (as a string) to the original digit (as a string)
                areaToDigit[to_string(area)] = digit;

                // Set this cell to be in the area
                grid[i][j] = to_string(area);

                // Mark surrounding cells as being in this area if they are
                // the same digit as the original digit of this cell
                mark(i, j, r, c, grid, digit, to_string(area));

                // Increment the area number ready for the next area
                area++;
            }
        }
    }

    // Get the number of cases
    int n;
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        // Get the start and end coordinates
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        // If the start and end positions are in different areas
        if(grid[r1][c1] != grid[r2][c2])
        {
            cout << "neither" << endl;
            continue;
        }
        // If both start and end positions are in the same area
        else
        {
            // If the original digit represents a binary user
            if(areaToDigit[grid[r1][c1]] == "0")
            {
                cout << "binary" << endl;
            }
            // If the original digit represents decimal user
            else
            {
                cout << "decimal" << endl;
            }
        }
    }

    return 0;
}
