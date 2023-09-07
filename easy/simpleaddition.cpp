#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Get the 2 numbers
    string a, b;
    cin >> a >> b;

    string out = ""; // Used to store the output
    
    // Get reverse iterators to iterate through the 2 numbers from right to left
    string::reverse_iterator x = a.rbegin();
    string::reverse_iterator y = b.rbegin();

    int c = 0; // The amount to carry between sums
               
    // While both numbers have digits left to sum
    while(x != a.rend() && y != b.rend())
    {
        // Get the digits to sum
        int m = (*x) - 48;
        int n = (*y) - 48;

        // Sum the digits along with the carry
        int s = m + n + c;

        // If the sum exceeds this column
        if(s > 9)
        {
            c = 1; // Set the carry
            s %= 10; // Find the remainder after removing the carry
        }
        // If the sum is within this column
        else
        {
            c = 0; // Set the carry
        }

        // Add the sum of the digits to the output
        out.append(to_string(s));

        // Get the next digits
        x++;
        y++;
    }

    // While the first number has digits left
    while(x != a.rend())
    {
        // Get the digit
        int m = (*x) - 48;

        // Sum the digit with the carry
        int s = m + c;

        // If the sum exceeds this column
        if(s > 9)
        {
            c = 1; // Set the carry
            s %= 10; // Find the remainder after removing the carry
        }
        // If the sum is within this column
        else
        {
            c = 0; // Set the carry
        }

        // Add the sum of the digit and carry to the output
        out.append(to_string(s));

        // Get the next digit
        x++;
    }

    // While the second number has digits left
    while(y != b.rend())
    {
        // Get the digit
        int n = (*y) - 48;

        // Sum the digit with the carry
        int s = n + c;

        // If the sum exceeds this column
        if(s > 9)
        {
            c = 1; // Set the carry
            s %= 10; // Find the remainder after removing the carry
        }
        // If the sum is within this column
        else
        {
            c = 0; // Set the carry
        }

        // Add the sum of the digit and carry to the output
        out.append(to_string(s));

        // Get the next digit
        y++;
    }

    // If there is a carry left at the end
    if(c == 1)
    {
        // Add 1 to the output
        out.append("1");
    }

    // Reverse the output to have it in the correct order from left to right
    reverse(out.begin(), out.end());
    cout << out << endl;

    return 0;
}
