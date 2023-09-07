#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n, m; // Get the number of candidates and number of values outputted
    cin >> n >> m;

    int maximum = 0; // The maximum correct answers a candidate has
    int candidate = 1; // That candidate's number

    // For each candidate
    for(int j = 1; j <= n; j++)
    {
        int correct = 0; // The number of correct answers the candidate has

        // For each value the candidate outputs
        for(int i = 1; i <= m; i++)
        {
            // Find the correct value
            string s = "";
            if(i % 3 == 0)
            {
                s.append("fizz");
            }
            if(i % 5 == 0)
            {
                s.append("buzz");
            }
            if(s == "")
            {
                s = to_string(i);
            }

            // Get the candidates value
            string x;
            cin >> x;

            // If the candidate's value is correct
            if(x == s)
            {
                correct++; // Increment tne number of correct answers
            }
        }

        // If the number of correct answers the candidate has the maximum seen
        if(correct > maximum)
        {
            maximum = correct; // Update the maximum correct answers
            candidate = j; // Set the candidate to this candidate
        }
    }

    cout << candidate << endl;

    return 0;
}
