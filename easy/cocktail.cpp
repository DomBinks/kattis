#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // Get number of potions and time to drink each potion
    int n, t;
    cin >> n >> t;

    // Put each potion into a vector
    vector<int> potions;
    for(int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        potions.push_back(x);
    }

    // Sort the vector
    sort(potions.begin(), potions.end(), greater<int>());

    vector<int>::iterator current = potions.begin();
    // For each potion after the current potion
    for(int i = 1; i < n; i++)
    {
        // If the rest of the potions can't be drunk within the time of this
        // potion
        if(*current <= (n - i) * t)
        {
           cout << "NO" << endl; 
           return 0;
        }

        // Go to the next potion
        current++; 
    }

    cout << "YES" << endl;

    return 0;
}
