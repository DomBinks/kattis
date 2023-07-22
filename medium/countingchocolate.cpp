#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Get the number of boxes
    int n;
    cin >> n;

    int target = 0; // The target number to get i.e. total split in half
    int biggest = 0; // The biggest box
    vector<int> boxes(n); // Stores all the boxes
    
    // For each box
    for(int &i : boxes)
    {
        cin >> i; // Get the box
        target += i; // Update the running total
        biggest = max(i, biggest); // Update the biggest box seen
    }

    // If there is an odd amount or 1 box contains over half
    if(target % 2 != 0 || biggest > (target / 2))
    {
        // Can't split the chocolate evenly
        cout << "NO" << endl;
        return 0;
    }
    else
    {
        // Set the target to be half the total amount of chocolate
        target /= 2;
    }

    // Remove the box with the biggest amount
    boxes.erase(find(boxes.begin(), boxes.end(), biggest));

    // We know we're going to have to combine some other boxes with the
    // biggest box to reach the target, so work out which values are possible
    // using combinations of the other boxes.
    // If the value needed alongside the biggest box to get to the target
    // is possible using the other boxes, then the chocolate can be split

    // Stores the values that are possible using the other boxes
    vector<int> possible(target-biggest+1, false);
    possible[0] = true;

    // For each box
    for(int i : boxes)
    {
        // For each possible value of a combination of the other boxes
        // (downwards to avoid using the same box twice)
        for(int j = (target-biggest); j >= 0; j--)
        {
            // If this value is already possible and adding this box to it is
            // still within range
            if(possible[j] && j+i <= (target-biggest))
            {
                // Set this value + this box as possible
                possible[j+i] = true;
            }
        }
    }

    // Check if it's possible to use other boxes alongside the biggest box
    // to get to the target amount
    cout << (possible[target-biggest] ? "YES" : "NO") << endl;

    return 0;
}
