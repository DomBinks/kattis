#include <bits/stdc++.h>

using namespace std;

int main()
{
    // For each case
    int t;
    cin >> t;
    while(t-- > 0)
    {
        // Get the number of grades
        double n;
        cin >> n;

        // Store each grade in a vector while finding the total
        vector<int> grades(n);
        double avg = 0.0;
        for(int &g : grades)
        {
            cin >> g;
            avg += g;
        }
        avg /= n; // Total -> average

        // Find each grade above the average
        double above = 0;
        for(int g : grades)
        {
            if(g > avg)
            {
                above++;
            }
        }
        above = above / n * 100.0; // Above -> average

        printf("%0.3f\%\n", above);
    }

    return 0;
}
