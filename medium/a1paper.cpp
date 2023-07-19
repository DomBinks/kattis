#include <iostream>
#include <math.h>

using namespace std;

int main()
{
    // Minimum tape is the tape needed for 2 A2 sheets
    double total = pow(2, -(3 / 4.0));

    // Get the number of inputs
    int n;
    cin >> n;

    int need = 2; // Number of sheets of the current size needed to get to A1
    // For each sheet size i.e. number of inputs
    for(int i = 2; i <= n; i++)
    {
        // Get the number of sheets
        int sheets;
        cin >> sheets;

        // Decrement need based on the number of sheets of this size we have
        // Leaves a number of sheets that will have to be made with glueing
        need -= sheets;

        // If we still need sheets of this size
        if(need > 0)
        {
            // Add to the total the glue needed to glue together 2 of the next
            // size for the number of sheets needed
            if((i+1) % 2 == 0)
            {
                total += (need * pow(2, -(((i+1) / 2 * 4) - 1) / 4.0));
            }
            if((i+1) % 2 != 0)
            {
                total += (need * pow(2, -(((i+1) / 2 * 4) + 1) / 4.0));
            }
        }

        // Double the sheets needed to adjust to the number of sheets on the
        // next size
        need *= 2;
    }

    // If no extra paper needed at the end
    if(need <= 0)
    {
        printf("%0.11f\n", total);
    }
    // If paper is still needed
    else
    {
        cout << "impossible" << endl;
    }
}
