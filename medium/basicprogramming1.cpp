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
        cout << "7" << endl;
    }
    else if(t == 2)
    {
        if(a[0] > a[1])
        {
            cout << "Bigger" << endl;
        }
        else if(a[0] == a[1])
        {
            cout << "Equal" << endl;
        }
        else
        {
            cout << "Smaller" << endl;
        }
    }
    else if(t == 3)
    {
        vector<int> nums = {a[0], a[1], a[2]}; // Get the first 3 numbers
        sort(nums.begin(), nums.end()); // Sort the numbers
        cout << nums[1] << endl; // Get the median(middle)
    }
    else if(t == 4)
    {
        long long total = 0;
        for(int i = 0; i < n; i++)
        {
            total += a[i];
        }
        cout << total << endl;
    }
    else if(t == 5)
    {
         long long total = 0;

        for(int i = 0; i < n; i++)
        {
            if((a[i] % 2) == 0) // Only add even numbers to the total
            {
                total += a[i];
            }
        }
        cout << total << endl;
    }
    else if(t == 6)
    {
        for(int i = 0; i < n; i++)
        {
            // Convert the number to a character index using % 26, and map this
            // to the correct ASCII value by adding 97 to get to the lower case
            // letter
            cout << static_cast<char>((a[i] % 26) + 97);
        }
        cout << endl;
    }
    else
    {
        int i = 0; // Starting index
        bool seen[n]; // Track seen indices
        for(int i = 0; i < n; i++)
        {
            seen[i] = false;
        }

        // Until one of the conditions has been met
        while(true)
        {
            i = a[i]; // Get the next index

            if(i >= n)
            {
                cout << "Out" << endl;
                break;
            }
            else if(i == (n-1))
            {
                cout << "Done" << endl;
                break;
            }
            else if(seen[i])
            {
                cout << "Cyclic" << endl;
                break;
            }
            else
            {
                seen[i] = true;
            }
        }
    }

    return 0;
}
