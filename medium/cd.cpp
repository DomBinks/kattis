#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Keep accepting cases
    while(true)
    {
        // Get the number of CDs in each collection
        int n, m;
        cin >> n >> m;

        // Terminate if the input is 0 0
        if(n == m && m == 0)
        {
            break;
        }

        // Store all the CDs in Jack's collection
        vector<int> jack;
        for(int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            jack.push_back(x);
        }

        int both = 0; // Stores the number of CDs in both collections
        int i = 0; // Stores the index in Jack's collection
        for(int j = 0; j < m; j++) // For each CD in Jill's collection
        {
            /// Get the next CD in Jill's collection
            int x;
            cin >> x;
            
            // If the index in Jack's collection points to a CD with a lower
            // number, keep advancing in Jack's collection
            while(jack[i] < x && i < (n-1))
            {
                i++;
            }
            
            // If Jack's index now points to the same number as Jill's CD
            if(jack[i] == x)
            {
                // Then they both have the CD with this number
                both++;
            }
            // If Jack's index isn't the same, then it means that Jack doesn't
            // have that CD, so has skipped to a CD with a higher number
        }

        cout << both << endl;
    }
    return 0;
}
