#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// Splits up the string into a vector of strings based on the splitter character
vector<string> split(string input, char splitter)
{
    vector<string> output; // Stores the output vector
    int length = input.length(); // Finds the length of he input
    int start = 0; // Tracks start of the current segment
    int end = 1; // Tracks end of the current segment

    while(end <= length) // While end is still on the string
    {
        if(input[end] == splitter) // If the splitter character is found
        {
            // Add the current segment to the output
            output.push_back(input.substr(start, end-start));
            // Move start and end to the beginning of the next segment
            start = end + 1;
            end = start + 1;
        }
        else // If the splitter character isn't found
            end++; // Increase the size of the current segment
    }
    // Add the last segment to the output
    output.push_back(input.substr(start, end-start));

    return output;
}

int main()
{
    string input;
    cin >> input;
    vector<string> inputs;
    int output = 0;

    inputs = split(input, ';'); // Split the input into groupings

    // For each grouping
    for(vector<string>::iterator i = inputs.begin(); i != inputs.end(); i++)
    {
        if((*i).find("-") == string::npos) // If it is just one group
            output++; // Increment output
        else // If it is a range of groups
        {
            // Split the range into the the first and second value
            vector<string> sides = split(*i, '-');
            int a = stoi(sides[0]);
            int b = stoi(sides[1]);
            
            // Subtract the second from the first to find the length of the
            // range(adding 1 to make the maths work)
            output += b - a + 1;
        }
    }

    cout << output << endl;
    return 0;
}
