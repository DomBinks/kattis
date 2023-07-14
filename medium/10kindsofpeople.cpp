#include <iostream>
#include <vector>
#include <queue>
#include<tuple>

using namespace std;

bool search(int r1, int c1, int r2, int c2, int r, int c, char **grid, char num)
{
    // If the current is the destination
    if(r1 == r2 && c1 == c2)
    {
        return true;
    }

    // Create a priority queue to store the positions to look at, based upon
    // the minimum Manhattan distance to the end
    priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;

    // If there is a cell above
    if(r1-1 >= 1)
    {
        // If the cell above contains num
        if(grid[r1-1][c1] == num)
        {
            // Add this position to the PQ
            pq.push(make_tuple(abs((r1-1)-r2)+abs(c1 - c2), r1-1, c1));
        }
    }
    // If there is a cell below
    if(r1+1 <= r)
    {
        // If the cell below contains num
        if(grid[r1+1][c1] == num)
        {
            // Add this position to the PQ
            pq.push(make_tuple(abs((r1+1)-r2)+abs(c1 - c2), r1+1, c1));
        }
    }
    // If there is a cell to the left
    if(c1-1 >= 1)
    {
        // If the cell to the left contains num
        if(grid[r1][c1-1] == num)
        {
            // Add this position to the PQ
            pq.push(make_tuple(abs(r1-r2)+abs((c1-1) - c2), r1, c1-1));
        }
    }
    // If there is a cell to the right
    if(c1+1 <= c)
    {
        // If the cell to the right contains num
        if(grid[r1][c1+1] == num)
        {
            // Add this position to the PQ
            pq.push(make_tuple(abs(r1-r2)+abs((c1+1) - c2), r1, c1+1));
        }
    }

    // While there are cells to investigate
    while(!pq.empty())
    {
        // Get the cell at the top of the heap
        tuple<int, int, int> t = pq.top();
        pq.pop();

        // If this cell has been found already
        if(grid[get<1>(t)][get<2>(t)] == 'X')
        {
            continue;
        }

        // Set the cell to found
        grid[get<1>(t)][get<2>(t)] = 'X';

        // If we can get to the end via this cell
        if(search(get<1>(t), get<2>(t), r2, c2, r, c, grid, num))
        {
            return true;
        }
    }

    // If we can't get to the end via any cell
    return false;
}

int main()
{
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Get number of rows and columns
    int r, c;
    cin >> r >> c;

    // Get the grid
    char grid[1001][1001];
    for(int i = 1; i <= r; i++)
    {
        string row;
        cin >> row;

        for(int j = 1; j <= c; j++)
        {
            grid[i][j] = row[j-1];
        }
    }

    // Get the number of cases
    int n;
    cin >> n;
    for(int m = 0; m < n; m++)
    {
        // Get the start and end coordinates
        int r1, c1, r2, c2;
        cin >> r1 >> c1 >> r2 >> c2;

        // If there can't possibly be a path as the start and end are different
        // digits
        if(grid[r1][c1] != grid[r2][c2])
        {
            cout << "neither" << endl;
            continue;
        }

        char num = grid[r1][c1]; // Store the digit we're searching for
        
        // Create a copy of the grid we can modify
        char **gridCopy = new char*[1001];
        for(int i = 1; i <= r; i++)
        {
            gridCopy[i] = new char[1001];
            for(int j = 1; j <= c; j++)
            {
                gridCopy[i][j] = grid[i][j];
            }
        }

        // Set the starting point as found
        gridCopy[r1][c1] = 'X';

        // If we can find a path from the start to the end
        if(search(r1, c1, r2, c2, r, c, gridCopy, num))
        {
            // If the digit represents a binary user
            if(num == '0')
            {
                cout << "binary" << endl;
            }
            // If the digit represents decimal user
            else
            {
                cout << "decimal" << endl;
            }
        }
        // If we can't find a path from the start to the end
        else
        {
            cout << "neither" << endl;
        }
    }

    return 0;
}
