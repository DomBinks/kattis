#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int n; // Number of cases
    cin >> n;

    map<string, string> names; // Stores each date's birthday
    map<string, int> scores; // Stores each dates's top score
    
    for(int i = 0; i < n; i++) // For each person
    {
        string name;
        int score;
        string date;
        cin >> name >> score >> date;

        // If there isn't someone with the given birthday yet
        if(names[date].empty())
        {
            // Add their birthday
            names[date] = name;
            scores[date] = score;
        }
        // If someone else has a birthday on the same date
        else
        {
            // If the new person's score is bigger than the previous person's
            if(score > scores[date])
            {
                // Replace with the new person
                names[date] = name;
                scores[date] = score;
            }
        }
    }

    vector<string> sortedNames; // Stores all names to be printed
    for(map<string, string>::iterator j = names.begin(); j != names.end(); j++)
    {
        sortedNames.push_back(j->second);
    }
    sort(sortedNames.begin(), sortedNames.end()); // Sort all the names

    cout << sortedNames.size() << endl; // Output the number of names
    for(vector<string>::iterator j = sortedNames.begin(); j != sortedNames.end(); j++)
    {
        cout << *j << endl; // Output each name
    }

    return 0;
}
