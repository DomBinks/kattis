#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    // Get number of cities
    int n;
    cin >> n;

    // Put each city into a vector
    vector<int> cities;
    for(int i = 0; i < n; i++)
    {
        int a;
        cin >> a;

        cities.push_back(a);
    }

    // Sort the vector
    sort(cities.begin(), cities.end());
    
    long long total = 0; // Keep track of the running total
    int min = *cities.begin(); // Find the minimum city

    // Get the first city after the minimum
    vector<int>::iterator current = ++cities.begin();

    // For all cities after the minimum
    while(current != cities.end())
    {
        total += min + *current; // Update the total with the highway to this city
        current++; // Go to the next city
    }

    cout << total << endl;
    return 0;
}
