#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
    // Get the number of players
    int n;
    cin >> n;

    // Stores the current white and black players
    // index 0 for offensive, index 1 for defensive
    string white[2];
    string black[2];

    // Stores the current white and black players in the order that they
    // arrived at the table
    vector<string> whitePlayers;
    vector<string> blackPlayers;

    // Stores the players waiting to play
    queue<string> waiting;
    
    // Put the first 4 players in the correct positions
    string start;
    cin >> start;
    white[0] = start;
    whitePlayers.push_back(start);
    cin >> start;
    black[0] = start;
    blackPlayers.push_back(start);
    cin >> start;
    white[1] = start;
    whitePlayers.push_back(start);
    cin >> start;
    black[1] = start;
    blackPlayers.push_back(start);

    // Put the rest of the players in the waiting queue
    for(int i = 0; i < (n - 4); i++)
    {
        string wait;
        cin >> wait;
        waiting.push(wait);
    }

    // Get the game string
    string game;
    cin >> game;

    vector<string> dynastyPlayers; // Stores strings of the current dynasties
    int dynastyGames = 0; // The number of consecutive games the dynasties won
    char currentTeam = 'X'; // The current team playing
    int currentTeamGames = -1; // The current team's consecutive wins

    // For each game in the string
    for(int i = 0; i < game.length(); i++)
    {
        // If the white team won
        if(game[i] == 'W')
        {
            // Swap the offensive and defensive players
            string tmp = white[0];
            white[0] = white[1];
            white[1] = tmp;

            // If the winning team has changed
            if(currentTeam != 'W') 
            {
                // Check if a new top dynasty has been created
                if(currentTeamGames >= dynastyGames)
                {
                    // If it isn't tied
                    if(currentTeamGames > dynastyGames)
                    {
                        // Clear the list of top dynasties
                        dynastyPlayers.clear();
                    }

                    // Put the players on the black team into a string
                    // based on the order they arrived at the table
                    string players = blackPlayers[0] + " " + blackPlayers[1];

                    // Add this string to the vector of current dynasties
                    dynastyPlayers.push_back(players);

                    // Set the number of games won by the top dynasties
                    dynastyGames = currentTeamGames;
                }

                // Setup the values for the white team
                currentTeam = 'W';
                currentTeamGames = 1;
            }
            // If the winning team hasn't changed
            else
            {
                currentTeamGames++;
            }

            // Put the black defensive player to the back of the queue
            // and put the player at the front of the queue as the black
            // offensive player
            waiting.push(black[1]);
            blackPlayers.erase(find(blackPlayers.begin(), blackPlayers.end(), black[1]));
            black[1] = black[0];
            black[0] = waiting.front();
            blackPlayers.push_back(waiting.front());
            waiting.pop();
        }
        // If the black team won
        else
        {
            // Swap the offensive and defensive players
            string tmp = black[0];
            black[0] = black[1];
            black[1] = tmp;

            // If the winning team has changed
            if(currentTeam != 'B') 
            {
                // Check if a new top dynasty has been created
                if(currentTeamGames >= dynastyGames)
                {
                    // If it isn't tied
                    if(currentTeamGames > dynastyGames)
                    {
                        // Clear the list of top dynasties
                        dynastyPlayers.clear();
                    }

                    // Put the players on the white team into a string
                    // based on the order they arrived at the table
                    string players = whitePlayers[0] + " " + whitePlayers[1];

                    // Add this string to the vector of current dynasties
                    dynastyPlayers.push_back(players);

                    // Set the number of games won by the top dynasties
                    dynastyGames = currentTeamGames;
                }

                // Setup the values for the black team
                currentTeam = 'B';
                currentTeamGames = 1;
            }
            // If the winning team hasn't changed
            else
            {
                currentTeamGames++;
            }

            // Put the white defensive player to the back of the queue
            // and put the player at the front of the queue as the white
            // offensive player
            waiting.push(white[1]);
            whitePlayers.erase(find(whitePlayers.begin(), whitePlayers.end(), white[1]));
            white[1] = white[0];
            white[0] = waiting.front();
            whitePlayers.push_back(waiting.front());
            waiting.pop();
        }
    }

    // Check if the last team to win is a top dynasty
    if(currentTeamGames >= dynastyGames)
    {
        // If it isn't tied
        if(currentTeamGames > dynastyGames)
        {
            // Clear the list of top dynasties
            dynastyPlayers.clear();
        }

        // Put the players on the winning team into a string
        // based on the order they arrived at the table
        string players;
        if(currentTeam == 'B')
        {
            players = blackPlayers[0] + " " + blackPlayers[1];
        }
        else
        {
            players = whitePlayers[0] + " " + whitePlayers[1];
        }

        // Add this string to the vector of current dynasties
        dynastyPlayers.push_back(players);
    }

    // Print out all the top dynasties
    for(string players : dynastyPlayers)
    {
        cout << players << endl;
    }

    return 0;
}
