#include <bits/stdc++.h>

using namespace std;

int main()
{
    int high = 1000; // Upper bound of the range we're searching in
    int low = 1; // Lower bound of the range we're searching in
    int num = 500; // Current number we're guessing
                   
    cout << num << endl; // Guess the middle number(500) to start

    int guesses = 1; // Number of guesses made so far
                     
    string res; // Used to store the response
    cin >> res; // Get the response

    // While we aren't correct and have guesses left
    // use a binary search to get to the correct number
    while(res != "correct" && guesses < 10)
    {
        // If their number is lower
        if(res == "lower")
        {
            high = num; // This number is the new upper bound
            num -= (high - low + 1) / 2; // Decrease the number by half the range
                                         // (+1 for ceiling division)
        }
        else
        {
            low = num; // This number is the new lower bound
            num += (high - low + 1) / 2; // Increase the number by half the range
                                         // (+1 for ceiling division)
        }

        cout << num << endl; // Guess the new number
        guesses++; // Increment guesses made

        cin >> res; // Get the response
    }

    return 0;
}
