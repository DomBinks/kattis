#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // Get number of buses
    int n;
    cin >> n;

    // Get each bus
    vector<int> buses(n);
    for(int &bus : buses)
    {
        cin >> bus;
    }

    // Sort the list of buses
    sort(buses.begin(), buses.end());

    vector<string> output; // Used to store the output strings

    // Used to loop through the buses
    vector<int>::iterator it = buses.begin();
    int start = *it; // Start of a sequence of buses
    int prev = *it; // Previous bus in the sequence of buses
    it++; // Go to the next bus

    // While there are buses left to look at
    while(it != buses.end())
    {
        // If the this bus is one greater than the previous
        if(*it == prev+1)
        {
            // Set the previous to this bus
            prev = *it;
        }
        // If the this bus isn't greater than the previous
        else
        {
            // If there is only 1 bus in the sequence
            if(start == prev)
            {
                // At that bus as a string to the output vector
                output.push_back(to_string(start));
            }
            // If there are only 2 buses in the sequence
            else if(start + 1 == prev)
            {
                // Add both buses as strings to the output vector individually
                output.push_back(to_string(start));
                output.push_back(to_string(prev));
            }
            // If there are more than 2 buses in the sequence
            else
            {
                // Add the range of buses as a string to the output vector
                output.push_back(to_string(start)+"-"+to_string(prev));
            }

            // Set the starting bus and previous bus to this bus
            start = *it;
            prev = *it;
        }

        // Get the next bus
        it++;
    }
    // If the searching ends with a sequence of 1 bus
    if(start == prev)
    {
        // At that bus as a string to the output vector
        output.push_back(to_string(start));
    }
    // If the searching ends with a sequence of 2 buses
    else if(start + 1 == prev)
    {
        // Add both buses as strings to the output vector individually
        output.push_back(to_string(start));
        output.push_back(to_string(prev));
    }
    // If the searching ends with a sequence of more than 2 buses
    else
    {
        // Add the range of buses as a string to the output vector
        output.push_back(to_string(start)+"-"+to_string(prev));
    }

    vector<string>::iterator out = output.begin();

    // Output the first bus range in the output vector
    cout << *out;
    out++;
    
    // Loop over the rest of the bus ranges in the output vector
    while(out != output.end())
    {
        // Output the bus range
        cout << " " << *out;
        out++;
    }
    cout << endl;
    
    return 0;
}
