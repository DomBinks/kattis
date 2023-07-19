#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int num; // Stores the current number
    while(cin >> num) // While there is a number left
    {
        vector<int> divisors = {1}; // Stores the proper divisors (1 is always a proper divisor)
        int total = 1; // Stores the total of the proper divisors
        
        // For all numbers from 2 to half num
        for(int i = 2; i*i <= num; i++)
        {
            // If i is a divisor
            if(num % i == 0)
            {
                divisors.push_back(i); // Add it to the vector of divisors
                total += i; // Add it to the total

                if(i*i < num) // If it's a divisor pair
                {
                    divisors.push_back(num / i); // Add the other divisor to the vector of divisors
                    total += (num / i); // Add the other divisor to the vector of divisors
                }
            }
        }

        cout << num; // Print the number
        if(total == num) // If it's a perfect number
        {
            cout << " perfect" << endl;
        }
        else if(total >= num-2 && total <= num+2) // If it's in the almost perfect range
        {
            cout << " almost perfect" << endl;
        }
        else // If it's not in the almost perfect range
        {
            cout << " not perfect" << endl;
        }
    }

    return 0;
}
