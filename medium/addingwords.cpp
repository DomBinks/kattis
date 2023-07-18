#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

int main()
{
    // Get the initial command
    string cmd;
    cin >> cmd;

    // Create maps to map words to numbers and numbers to words
    map<string, int> wordToNum;
    map<int, string> numToWord;

    // While there is still something to read;
    while(!cin.eof())
    {
        // If the command is clear
        if(cmd == "clear")
        {
            // Set both maps to empty maps
            wordToNum.clear();
            numToWord.clear();
        }
        // If the command is def
        else if(cmd == "def")
        {
            // Get the word and number to set that word to
            string word;
            int num;
            cin >> word;
            cin >> num;

            // Update the maps
            wordToNum[word] = num;
            numToWord[num] = word;
        }
        // If the command is calc
        else
        {
            vector<string> out; // Create a vector to store the parts of the output
            int total = 0; // Store the total of the calculation
            bool unknown = false; // Store whether a word with an unknown number has been seen

            // Get the word and the operator
            string word, op;
            cin >> word >> op;

            // Add the word and operator to the output vector
            out.push_back(word);
            out.push_back(op);
            
            // If the word has a mapping
            if(wordToNum.count(word) > 0)
            {
                // Set the starting total to that word's value
                total = wordToNum[word];
            }
            // If the word doesn't have a mapping
            else
            {
                // Set the total to be unknown
                unknown = true;
            }
            
            // While there are extra parts of the calculation left
            while(op != "=")
            {
                cin >> word; // Get the word to be added or subtracted
                out.push_back(word); // Add the word to the output vector

                // If it's an addition operation to perform
                if(op == "+")
                {
                    // If the word has a mapping
                    if(wordToNum.count(word) > 0) 
                    {
                        // Add the word's value to the total
                        total += wordToNum[word];
                    }
                    // If the word doesn't have a mapping
                    else
                    {
                        // Set the total to be unknown
                        unknown = true;
                    }
                }
                // If it's a subtraction operation to perform
                else
                {
                    // If the word has a mapping
                    if(wordToNum.count(word) > 0) 
                    {
                        // Subtract that word's value from the total
                        total -= wordToNum[word];
                    }
                    // If the word doesn't have a mapping
                    else
                    {
                        // Set the total to be unknown
                        unknown = true;
                    }
                }

                cin >> op; // Get the next operator
                out.push_back(op); // Add the operator to the output vector
            }

            // Print each part of the output in the output vector
            for(int i = 0; i < out.size(); i++)
            {
                cout << out[i] << " ";
            }

            // If the total is unknown or there is no mapping for the total value
            if(unknown || numToWord.count(total) <= 0)
            {
                cout << "unknown" << endl;
            }
            // If the total is known and there is a mapping for the total value
            else
            {
                cout << numToWord[total] << endl;
            }
        }

        // Get the next command to perform or EOF
        cin >> cmd;
    }

    return 0;
}
