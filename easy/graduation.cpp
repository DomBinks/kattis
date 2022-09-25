#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // Get input
    int N, M, K; // Rows, Cols, Classses
    cin >> N >> M >> K;
    vector<string> rows; // Input rows
    vector<char> seen; // Classes seen
    int output = 0; // Output

    for(int i = 0; i < N; i++) // Get all the rows
    {
        string row;
        cin >> row;
        rows.push_back(row);
    }

    for(int i = 0; i < M; i++) // For each column
    {
        vector<char> newSeen; // Stores new classes in this column
        bool inSeen = false; // Tracks if an already seen classes is in the col
        for(int j = 0; j < N; j++) // For each row
        {
            // If the class is new add it to newSeen
            if(find(seen.begin(), seen.end(), rows[j][i]) == seen.end())
                newSeen.push_back(rows[j][i]);
            // If the class has been seen then set the flag
            // Don't break as there might be more new classes
            else
                inSeen = true;
        }

        if(!inSeen )// If the flag hasn't been set
            output++; // Increment the output as this col can wear a new colour

        // Add all the new classes to the main list
        seen.insert(seen.end(), newSeen.begin(), newSeen.end());
    }

    cout << output << endl;
    return 0;
}
