#include <bits/stdc++.h>

using namespace std;

int main()
{
    int h, n; // Get the number of houses and cables
    cin >> h >> n;

    // Stores the houses each house is connected to
    map<int, vector<int>> connected;

    // For each cable
    for(int i = 0; i < n; i++)
    {
        // Get the 2 houses
        int a, b;
        cin >> a >> b;

        // Add the pairs of houses to each house's connected list
        connected[a].push_back(b);
        connected[b].push_back(a);
    }

    map<int, bool> seen; // Stores the houses that are connected
    list<int> toAdd = {}; // Stores the houses to process

    seen[1] = true; // Set house 1 as connected

    // Add all the houses connected to house 1 to the list of houses to process
    for(int i : connected[1])
    {
        toAdd.push_back(i);
    }

    // While there are houses to process
    while(!toAdd.empty())
    {
        // Get the first house to process
        int x = toAdd.front();
        toAdd.pop_front();

        // If this house hasn't been processed
        if(!seen[x])
        {
            seen[x] = true; // Set this house as connected
                            
            // For each house connected to this house
            for(int i : connected[x])
            {
                // If this house hasn't been processed
                if(!seen[i])
                {
                    // Add it to the list of houses to process
                    toAdd.push_back(i);
                }
            }
        }
    }

    // Stores the houses that are missing
    vector<int> missing = {};

    // For each house number
    for(int i = 1; i <= h; i++)
    {
        // If this house isn't connected
        if(!seen[i])
        {
            // Add it to the list of missing houses
            missing.push_back(i);
        }
    }

    // If there are no houses missing
    if(missing.empty())
    {
        cout << "Connected" << endl;
    }
    // If there are houses missing
    else
    {
        // Print the missing
        for(int i : missing)
        {
            cout << i << endl;
        }
    }

    return 0;
}
