#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Get the players
    string p1, p2;
    cin >> p1 >> p2;

    // Get the number of matches
    int n;
    cin >> n;

    // Get the input ready for getline
    cin.ignore(256, '\n');

    // For each match
    while(n-- > 0)
    {
        int p1Wins = 0; // Stores player 1's wins
        int p2Wins = 0; // Stores player 2's wins
        string verdict = "da"; // Stores the verdict of if the game is valid

        // Get the line for this match
        string setsLine;
        getline(cin, setsLine);

        vector<string> sets; // Stores each set

        // While there are still sets to pull from the line
        while(find(setsLine.begin(), setsLine.end(), ' ') != setsLine.end())
        {
            string set = setsLine.substr(0, setsLine.find(" ")); // Get the set
            sets.push_back(set); // Add the set to the vector of sets
            setsLine.erase(0, setsLine.find(" ")+1); // Remove this set from the line
        }
        sets.push_back(setsLine); // Add the last set to the vector of sets

        // Foe each set
        for(int i = 0; i < sets.size(); i++)
        {
            string set = sets[i]; // Get this set
            int p1Score = 0; // Stores player 1's games won
            int p2Score = 0; // Stores player 2's games won
            int border = set.find(":"); // Find where the ':' is
            p1Score = stoi(set.substr(0, border)); // Get player 1's games won
            p2Score = stoi(set.substr(border+1, set.size())); // Get player 2's games won
            
            // If the set is valid
            if(
                // Base case
                (abs(p1Score - p2Score) >= 2 && max(p1Score, p2Score) == 6) ||
                // 7 case that's always allowed
                (min(p1Score, p2Score) == 5 && max(p1Score, p2Score) == 7) ||
                // Special case allowed for first 2 sets
                (min(p1Score, p2Score) == 6 && max(p1Score, p2Score) == 7 && i < 2) ||
                // Special case for third set
                (abs(p1Score - p2Score) == 2 && max(p1Score, p2Score) > 6 && i >= 2)
            )
            {
                // Increment the player's sets won if they have the higher score
                if(p1Score > p2Score)
                {
                    p1Wins++;
                }
                else
                {
                    p2Wins++;
                }
            }
            // If the set isn't valid
            else
            {
                verdict = "ne";
            }
        }

        // If there is no overall winner, more than 3 games are played, or
        // federer loses a set
        if(
            max(p1Wins, p2Wins) != 2 ||
            sets.size() > 3 ||
            (p1 == "federer" && p2Wins > 0) ||
            (p2 == "federer" && p1Wins > 0)

        )
        {
            verdict = "ne";
        }

        cout << verdict << endl;
    }

    return 0;
}
