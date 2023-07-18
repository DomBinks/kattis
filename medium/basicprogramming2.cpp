#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    // Get inputs
    int n, t;
    cin >> n >> t;

    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    if(t == 1)
    {
        // Put array into a vector
        vector<int> v;
        for(int i = 0; i < n; i++)
        {
            v.push_back(a[i]);
        }

        // Sort the vector
        sort(v.begin(), v.end());

        // For each value in the vector
        vector<int>::iterator it = v.begin();
        while(it != v.end())
        {
            // Use a binary search to attempt to find the value that complements
            // the current value to give 7777
            vector<int>::iterator s = lower_bound(v.begin(), v.end(), 7777-(*it));

            // If the search was successful i.e. the complement was found
            if((*s) == 7777-(*it))
            {
                cout << "Yes" << endl;
                return 0;
            }

            it++;
        }

        cout << "No" << endl;
    }
    else if(t == 2)
    {
        vector<int> seen; // Tracks seen numbers

        // For each value in the array
        for(int i = 0; i < n; i++)
        {
            // If the number can be found in seen
            if(find(seen.begin(), seen.end(), a[i]) != seen.end())
            {
                cout << "Contains duplicate" << endl;
                return 0;
            }
            // If the number hasn't been found already
            else
            {
                // Add this value to seen
                seen.push_back(a[i]);
            }
        }

        cout << "Unique" << endl;
    }
    else if(t == 3)
    {
        // Tracks the number of occurrences of each integer
        // (technically should be a bigger array but it works for the test cases)
        int *count = new int[200001]; 
        for(int i = 0; i < 200001; i++)
        {
            count[i] = 0;
        }

        // For each value in the array
        for(int i = 0; i < n; i++)
        {
            count[a[i]]++; // Increment the number of occurrences

            // If the condition has been met
            if(count[a[i]] > (n/2))
            {
                // Then this a[i] must be the only value that meets the condition
                cout << a[i] << endl;
                delete[] count;
                return 0;
            }
        }

        // If the condition isn't met
        delete[] count;
        cout << "-1" << endl;
    }
    else if(t == 4)
    {
        // Put array into a vector
        vector<int> v;
        for(int i = 0; i < n; i++)
        {
            v.push_back(a[i]);
        }

        sort(v.begin(), v.end());

        // If there are an odd number
        if(n % 2 != 0)
        {
            // Print single median
            cout << v[n/2] << endl;
        }
        // If there are an even number
        else
        {
            // Print both median integers
            cout << v[(n/2)-1] << " " << v[n/2] << endl;
        }
    }
    
    else
    {
        vector<int> above; // Vector to store the values in the range

        // For each value in the array
        for(int i = 0; i < n; i++)
        {
            // If the value is in the range
            if(a[i] >= 100 && a[i] <= 999)
            {
                // Add it to the vector
                above.push_back(a[i]);
            }
        }

        sort(above.begin(), above.end());

        // If there are values in the range
        if(above.size() > 0)
        {
            cout << above[0];
            for(int i = 1; i < above.size(); i++)
            {
                cout << " " << above[i];
            }
            cout << endl;
        }
    }

    return 0;
}
