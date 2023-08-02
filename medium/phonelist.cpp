#include <bits/stdc++.h>

using namespace std;

// Used to check if a is shorter than b
bool comp(string &a, string &b)
{
    return a.size() < b.size();
}

int main()
{
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // For each case
    int t;
    cin >> t;
    while(t-- > 0)
    {
        // Get amount of numbers
        int n;
        cin >> n;

        // Stores each number
        vector<string> nums(n);

        // For each number
        for(string &s : nums)
        {
            // Add it to the vector
            cin >> s;
        }

        // Sort the vector of numbers by their length
        sort(nums.begin(), nums.end(), comp);

        map<string, int> seen; // Keeps track of seen prefixes
        bool prefix = false; // Whether a prefix has been seen twice

        // For each number
        for(string num : nums)
        {
            // For each character in the number
            for(int i = 1; i <= num.size(); i++)
            {
                // Get the substr to that character (excluding)
                string substr = num.substr(0,i);
                
                // If this prefix has been seen
                if(seen.count(substr) > 0)
                {
                    // Mark a prefix as having been seen twice
                    prefix = true;
                }
            }

            // Set this number as seen
            seen[num] = 1;
        }

        // If a prefix has been seen twice
        if(prefix)
        {
            cout << "NO" << endl;
        }
        // If each prefix is unique
        else
        {
            cout << "YES" << endl;
        }
    }

    return 0;
}
