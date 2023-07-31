#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Get the number of test cases
    int t;
    cin >> t;
    cin.ignore(256, '\n');
   
    // For each test case
    while(t-- > 0)
    {
        // Get the line with the noises
        string line;
        getline(cin, line);

        vector<string> noises; // Stores the noises

        // Put each noise into the vector
        char *noise;
        noise = strtok(const_cast<char*>(line.c_str()), " ");
        while(noise != nullptr)
        {
            noises.push_back(string(noise));
            noise = strtok(nullptr, " ");
        }

        // For each animal that makes a noise
        getline(cin, line);
        while(line != "what does the fox say?")
        {
            // Get the start of the line
            noise = strtok(const_cast<char*>(line.c_str()), " ");
            noise = strtok(nullptr, " ");

            // Get the noises that animal makes
            noise = strtok(nullptr, " ");
            while(noise != nullptr)
            {
                // While that noise can be found in the vector of noises
                auto it = find(noises.begin(), noises.end(), string(noise));
                while(it != noises.end())
                {
                    // Remove that noise from the vector
                    noises.erase(it);
                    it = find(noises.begin(), noises.end(), string(noise));
                }

                // Get the next noise
                noise = strtok(nullptr, " ");
            }

            // Get the next animal
            getline(cin, line);
        }

        // For each noise left in the vector of noises
        for(string s : noises)
        {
            // Print that noise
            cout << s << " ";
        }
        cout << endl;
    }

    return 0;
}
