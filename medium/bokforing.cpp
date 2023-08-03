#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    // Get the number of people and the number of events
    int n, q;
    cin >> n >> q;

    // Stores the number of kroners everyone has if their amount has been set
    // by a SET event
    map<int, int> *kroners = new map<int,int>;
    int s = 0; // The current default amount of kroners everyone has

    // For every event
    while(q-- > 0)
    {
        // Get the event
        string event;
        cin >> event;

        if(event == "SET")
        {
            // Get the person and the amount
            int p, a;
            cin >> p >> a;

            // Map this person to have this amount
            (*kroners)[p] = a;
        }
        if(event == "PRINT")
        {
            // Get the person
            int p;
            cin >> p;

            // If the person has a map entry i.e. manually set amount
            if((*kroners).count(p) > 0)
            {
                // Get their kroners from the map
                cout << (*kroners)[p] << endl;
            }
            // If the person has the default amount of kroners
            else
            {
                // Print the default amount
                cout << s << endl;
            }
        }
        if(event == "RESTART")
        {
            // Get the new default amount of kroners
            cin >> s;

            delete kroners; // Delete the previous map
            kroners = new map<int, int>; // Create a new blank map
        }
    }

    return 0;
}
