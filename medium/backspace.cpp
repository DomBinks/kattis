#include <iostream>

using namespace std;

int main()
{
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Get the input string
    string input;
    cin >> input;

    // Store the output string
    string output;
    
    // For each character in the input string
    for(int i = 0; i < input.size(); i++)
    {
        // If it isn't a backspace
        if(input[i] != '<')
        {
            // Add the character to the output
            output.push_back(input[i]);
        }
        // If it's a backspace
        else
        {
            // If there is a character that can be removed in the output
            if(!output.empty())
            {
                // Remove that character
                output.erase(--output.end());
            }
        }
    }

    // Print the output
    cout << output << endl;

    return 0;
}
