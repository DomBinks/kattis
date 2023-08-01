#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Get number of trips
    int n;
    cin >> n;

    // Map a country to each visit
    map<string, vector<int>> visits;

    // Stores current country and visit year
    string country;
    int year;

    // For each trip
    while(n-- > 0)
    {
        // Get the country and year
        cin >> country >> year;

        // Add it to the list of years for that country
        visits[country].push_back(year);
    }

    // For each country-visits pair in the map
    for(map<string, vector<int>>::value_type & p : visits)
    {
        // Sort the list of visits
        sort(p.second.begin(), p.second.end());
    }

    // Get the number of queries
    cin >> n;

    // For each query
    while(n-- > 0)
    {
        // Get the country and the position in the list
        cin >> country >> year;

        // Print the year for that position, -1 as 0 indexed
        cout << visits[country][year-1] << endl;
    }

    return 0;
}
