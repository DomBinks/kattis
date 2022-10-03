#include <iostream>
#include <string>
using namespace std;

int main()
{
    int n;
    cin >> n;

    cin.ignore(); // Makes the system wait for input
 
    while(n-- > 0) // For each case
    {
        string sentence;
        getline(cin, sentence); // Get the sentence

        // Compares the first part of the string to "Simon says "
        if(sentence.substr(0, 11).compare("Simon says ") == 0)
            // Output the second part of the string if Simon says
            cout << sentence.substr(11, sentence.length()) << endl;
    }

    return 0;
}
