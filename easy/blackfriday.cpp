#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Get the group size
    int n;
    cin >> n;

    // Create a map to map each die face to a vector of players that got that
    // score
    map<int, vector<int>> seen;
    for(int i = 1; i <= 6; i++)
    {
        seen[i] = {};
    }

    // For each person in the group
    for(int i = 1; i <= n; i++)
    {
        // Get their roll
        int a;
        cin >> a;
        
        // Add the person's position into the map using the score as the key
        seen[a].push_back(i);
    }

    // For each face in decreasing order
    for(int i = 6; i > 0; i--)
    {
        // If only 1 person got this score
        if(seen[i].size() == 1)
        {
            // Print their position in the queue
            cout << seen[i][0] << endl;
            return 0;
        }
    }

    cout << "none" << endl;
    return 0;
}
