#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // Get the number of test cases
    int t;
    cin >> t;

    // All the possible numbers that can be entered into the keypad
    vector<int> possible = {
        1, 2, 3, 4, 5, 6, 7, 8, 9,
        10, 11, 12, 13, 14, 15, 16, 17, 18, 19,
        20, 22, 23, 25, 26, 28, 29,
        33, 36, 39,
        40, 44, 45, 46, 47, 48, 49,
        50, 55, 56, 58, 59,
        66, 69,
        70, 77, 78, 79,
        80, 88, 89,
        99,
        100,
        110, 111, 112, 113, 114, 115, 116, 117, 118, 119,
        120, 122, 123, 125, 126, 128, 129,
        133, 136, 139,
        140, 144, 145, 146, 147, 148, 149,
        150, 155, 156, 158, 159,
        166, 169,
        170, 177, 178, 179,
        180, 188, 189,
        199,
        200,
    };

    // For each test case
    while(t-- > 0)
    {
        // Get the number to enter
        int n;
        cin >> n;

        int closest = 999; // Set the closest so far to a big number
        
        // Loop over each number in the vector that is smaller than the target
        vector<int>::iterator it = possible.begin();
        while(it != possible.end() && *it <= n)
        {
            // If this number is the closest seen so far
            if(abs(*it - n) < abs(closest - n))
            {
                closest = *it; // Update closest
            }

            it++;
        }

        // Check the number greater than the target if there is one
        if(it != possible.end())
        {
            if(abs(*it - n) < abs(closest - n))
            {
                closest = *it;
            }
        }

        cout << closest << endl;
    }
    return 0;
}
