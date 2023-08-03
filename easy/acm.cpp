#include <bits/stdc++.h>

using namespace std;

int main()
{
    map<char, int> problemToScore; // Stores the current score for a problem
    map<char, bool> solved; // Stores whether a problem has been solved

    int right = 0; // Number of right solutions
    int total = 0; // Total score of right solutions

    // Until EOF
    while(true)
    {
        // Get the time
        int time;
        cin >> time;

        // If EOF
        if(time == -1)
        {
            break;
        }

        // Get the problem
        char problem;
        cin >> problem;

        // Get the verdict
        string verdict;
        cin >> verdict;

        // If the problem is solved
        if(verdict == "right")
        {
            solved[problem] = true; // Set the problem as solved

            // If there haven't been any wrong submissions
            if(problemToScore.count(problem) == 0)
            {
                // Set the score to the time
                problemToScore[problem] = time;
            }
            // If there have been wrong submissions
            else
            {
                // Add the time to the penalty time
                problemToScore[problem] += time;
            }

            right++; // Increment number of problems solved
            total += problemToScore[problem]; // Add the score to the total
        }
        // If the ssssolution is wrong
        else
        {
            // If there are no penalties for this problem so far
            if(problemToScore.count(problem) == 0)
            {
                // Start the score at 20
                problemToScore[problem] = 20;
            }
            // If there are penalties for this problem already
            else
            {
                // Add an extra penalty time
                problemToScore[problem] += 20;
            }
        }
    }

    cout << right << " " << total << endl;

    return 0;
}
