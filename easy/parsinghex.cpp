#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<string> lines; // Stores the input lines

    // While there are more lines
    while(!cin.eof())
    {
        string line;
        getline(cin, line); // Get the line
        lines.push_back(line); // Add the line to the vector
    }

    // For each line
    for(string line : lines)
    {
        string hex = ""; // Stores the current hex number

        // For each character in the line
        for(int x = 0; x < line.size(); x++)
        {
            char c = line[x]; // Get the character

            // If the character is part of a hex string:
            // No current hex number and c is 0
            // The current hex number is 0 and c is x or X
            // The current hex number begins with 0x or 0X and c is 
            // 0-9 or a-f or A-F
            if(
                (hex == "" && c == '0') ||
                (hex == "0" && (c == 'X' || c == 'x')) ||
                (
                    (
                        (hex[0] == '0') && (hex[1] == 'x' || hex[1] == 'X')
                    ) &&
                    (
                        (c >= '0' && c <= '9') ||
                        (c >= 'a' && c <= 'f') ||
                        (c >= 'A' && c <= 'F')
                    )
                )
            )
            {
                // Append this character to the current hex number string
                hex = hex + c;
            }
            // If this character isn't part of the current hex number,
            // and there is a current hex number (> 2 as more than just 0x or 0X)
            else if(hex.size() > 2)
            {
                unsigned int decimal = 0; // Stores the decimal conversion

                // For each character that's part of the actual hex number
                for(int i = 2; i < hex.size(); i++)
                {
                    // Move the current conversion to the next hex column
                    decimal *= 16;

                    // Convert the character to the int value of that hex
                    // digit, and add to the decimal conversion
                    if(hex[i] >= '0' && hex[i] <= '9')
                    {
                        decimal += (hex[i] - 48);
                    }
                    else if(hex[i] >= 'a' && hex[i] <= 'f')
                    {
                        decimal += (hex[i] - 87);
                    }
                    else
                    {
                        decimal += (hex[i] - 55);
                    }
                }

                // Print the hex number alongside the decimal conversion
                cout << hex << " " << decimal << endl;

                // Reset the current hex number
                hex = "";
            }
            // If there isn't a hex number more than 0x or 0X
            else
            {
                // Reset the current hex number
                hex = "";
            }
        }

        // At the end if there is a hex number to output
        if(hex.size() > 2)
        {
            unsigned int decimal = 0;

            for(int i = 2; i < hex.size(); i++)
            {
                decimal *= 16;

                if(hex[i] >= '0' && hex[i] <= '9')
                {
                    decimal += (hex[i] - 48);
                }
                else if(hex[i] >= 'a' && hex[i] <= 'f')
                {
                    decimal += (hex[i] - 87);
                }
                else
                {
                    decimal += (hex[i] - 55);
                }
            }

            cout << hex << " " << decimal << endl;
        }
    }

    return 0;
}
