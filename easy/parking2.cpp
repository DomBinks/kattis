#include <iostream>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    // Get number of test cases
    int t;
    cin >> t;

    // For each test case
    while (t-- > 0)
    {
        // Get number of shops
        int n;
        cin >> n;
        
        // Store max and min shop value
        int max = 0;
        int min = 100;

        // For each shop
        for(int i = 0; i < n; i++)
        {
            // Get the shop
            int x;
            cin >> x;

            // Update max and min
            if(x > max)
            {
                max = x;
            }
            if(x < min)
            {
                min = x;
            }
        }

        // Optimal spot to park is at the minimum shop.
        // Therefore the minimum distance is the distance from the minimum shop
        // to the maximum shop, times 2 as you have to travel there and back.
        cout << (max - min) * 2 << endl;
    }

    return 0;
}
