#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int main()
{
    // Get the names of everyone in the queue
    int numNames;
    cin >> numNames;

    // Add everyone to the queue
    vector<string> names;
    for(int i = 0; i < numNames; i++)
    {
        string name;
        cin >> name;
        names.push_back(name);
    }

    // Get the number of changes to the queue
    int numChanges;
    cin >> numChanges;
    cin.ignore();

    // For each change
    for(int i = 0; i < numChanges; i++)
    {
        string changeName;

        // Get the change to make and the name(s)
        getline(cin, changeName);

        // If someone is cutting in
        if(changeName.substr(0, 3) == "cut")
        {
            // Get the names portion of the string
            string name = changeName.substr(4, changeName.length()-4);
            
            // Find the space between the names
            string::iterator space = find(name.begin(), name.end(), ' ');

            // Get the strings of the name of the person cutting in and the person being cut in front of
            string cutter = name.substr(0, space - name.begin());
            string infront = name.substr(space - name.begin() + 1, name.length() - (space - name.begin()));

            // Find the person being cut in front of in the queue
            vector<string>::iterator it = find(names.begin(), names.end(), infront);

            if(it != names.end())
            {
                // Add the person cutting in front to the queue
                names.insert(it, cutter);
            }
        }
                 
        // If someone is leaving the queue
        if(changeName.substr(0, 5) == "leave")
        {
            // Get the name of the person leaving
            string name = changeName.substr(6, changeName.length()-6);

            // Find the name in the queue
            vector<string>::iterator it = find(names.begin(), names.end(), name);

            if(it != names.end())
            {
                // Remove that person from the queue
                names.erase(it);
            }
        }
    }

    // Loop over the queue
    for(string name : names)
    {
        // Print out each name
        cout << name << endl;
    }

    return 0;
}
