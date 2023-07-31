#include <bits/stdc++.h>

using namespace std;

// Returns if m1 beats m2
bool beats(string m1, string m2)
{
    if(m1 == "rock" && m2 == "paper")
    {
        return false;
    }
    else if(m1 == "rock" && m2 == "scissors")
    {
        return true;
    }
    else if(m1 == "paper" && m2 == "rock")
    {
        return true;
    }
    else if(m1 == "paper" && m2 == "scissors")
    {
        return false;
    }
    else if(m1 == "scissors" && m2 == "paper")
    {
        return true;
    }
    else if(m1 == "scissors" && m2 == "rock")
    {
        return false;
    }

    return false; // Needed to keep the compiler happy
}

int main()
{
    int n, k;
    while(true)
    {
        // Get the number of players and number of games each player plays
        cin >> n;
        if(n == 0)
        {
            // Break if end
            break;
        }
        cin >> k;

        // Track each players wins and loses
        vector<int> wins(n+1, 0);
        vector<int> loses(n+1, 0);

        // Calculate the total number of games played
        int games = k * n * (n-1) / 2;

        // For each game played
        for(int i = 0; i < games; i++)
        {
            // Get the players and their moves
            int p1, p2;
            string m1, m2;
            cin >> p1 >> m1 >> p2 >> m2;

            // If it's a draw
            if(m1 == m2)
            {
                continue;
            }

            // If m1 beats m2
            if(beats(m1, m2))
            {
                wins[p1]++;
                loses[p2]++;
            }
            // If m2 beats m1
            else
            {
                loses[p1]++;
                wins[p2]++;
            }
        }

        // For each player
        for(int i = 1; i <= n; i++)
        {
            // If there would be a division by 0
            if(wins[i] + loses[i] <= 0)
            {
                printf("-\n");
            }
            else
            {
                // Calculate the win ratio, casting to ensure that floating
                // point division is used
                double ratio = wins[i] / static_cast<double>(wins[i] + loses[i]);
                printf("%0.3f\n", ratio);
            }
        }
        cout << endl;
    }

    return 0;
}
