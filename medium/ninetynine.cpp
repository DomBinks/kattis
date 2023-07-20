#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

int main()
{
    srand(time(NULL)); // Set the seed for random number generation

    // Start by outputting 1
    cout << 1 << endl;

    // Get the input from the computer
    int x;
    cin >> x;

    // Loop until 99 is reached
    while(true)
    {
        // We want to get to a multiple of 3, so then we can prevent the computer
        // from winning by outputting multiples of 3 up to 99

        // If we can get to a multiple of 3 by adding 1
        if((x+1) % 3 == 0)
        {
            // Output the computer's number + 1
            cout << x + 1 << endl;
        }
        // If we can get to a multiple of 3 by adding 2
        else if((x+2) % 3 == 0)
        {
            // Output the computer's number + 2
            cout << x + 2 << endl;
        }
        // If we can't get to a multiple of 3
        else
        {
            // Add 1 or 2 chosen at random to the computer's number as we
            // can't reach a multiple of 3
            cout << x + rand() % 2 + 1 << endl;
        }

        // If 99 has been reached
        if(x+1 == 99 || x+2 == 99)
        {
            break;
        }
        else
        {
            // Get the next number from the computer
            cin >> x;
        }
    }
    
    return 0;
}
