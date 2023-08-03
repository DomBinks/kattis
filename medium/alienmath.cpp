#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Get the number of digits i.e. the base
    int b;
    cin >> b;

    // Maps each digit to it's decimal equivalent
    map<string, int> digitToIndex;

    // For each digit
    for(int i = 0 ; i < b; i++)
    {
        // Get the digit
        string x;
        cin >> x;

        // Map this digit to the decimal equivalent
        digitToIndex[x] = i;
    }

    long long total = 0; // Stores the output as a decmial

    // Get the alien number
    string num;
    cin >> num;

    int s = 0; // The starting index of there current digit
    int e = 1; // Length of the current digit
               
    // For each character in the alien number
    for(int i = 1; i <= num.size(); i++)
    {
        // Get the current substring
        string sub = num.substr(s,e);

        // If the current substring isn't a digit
        if(digitToIndex.count(sub) == 0)
        {
            e++; // Increase the substring size
            continue; // Get the next character
        }
        // If the current substring is a digit
        else
        {
            total *= b; // Move the current total to the next column over
            total += digitToIndex[sub]; // Add this digit to the total
            s = i; // Set the starting index of the current digit to the next character
            e = 1; // Set the length of the current digit to 1
        }
    }

    cout << total << endl;

    return 0;
}
