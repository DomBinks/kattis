#include <iostream>

using namespace std;

int main()
{
    // Get number of statues to print
    int n;
    cin >> n;

    int printers = 1; // Current number of printers
    int printed = 0; // Current number of statues printed
    int days = 0; // Number of days passed
    while(printed < n) // While there are still statues to print
    {
        // If we can't print the rest today
        if(printers + printed < n)
        {
            int today = printers; // Note the number of printers we have today
            for(int i = 0; i < today; i++) // For each printer we have today
            {
                // If we need more printers to possibly print the rest tomorrow
                if((today - i) + printers + printed < n)
                {
                    // Print another printer
                    printers++;
                }
                // If we now have enough to print the rest using the remaining
                // prints today and all the printers tomorrow
                else
                {
                    // Use the rest of the prints today to print statues
                    printed++;
                }
            }
        }
        // If we can print the rest today
        else
        {
            // Print the rest
            printed += printers;
        }

        // Add this day to the days passed
        days++;
    }

    cout << days << endl;
    return 0;
}
