#include <iostream>
#include <algorithm>
#include <queue>
#include <map>

using namespace std;

int main()
{
    // Use fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Get n and k
    int n, k;
    cin >> n >> k;

    // Store the occurrences of each number in a map
    map<int, int> occurrences;
    for(int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        if(occurrences.find(num) == occurrences.end())
        {
            occurrences[num] = 1;
        }
        else
        {
            occurrences[num]++;
        }
    }

    // Store the amounts of occurrences
    priority_queue<int> amounts;

    // Put each amount of occurrences into the PQ
    map<int, int>::iterator it = occurrences.begin();
    while(it != occurrences.end())
    {
        amounts.push(it->second);
        it++;
    }

    // For the number of removals
    while(k > 0)
    {
        int x = amounts.top(); // Get the highest amount of occurrences
        amounts.pop(); // Remove it from the PQ
        amounts.push(x-1); // Add the decremented amount of occurrences to the PQ
        k--; // Decrement the number of removals left
    }

    // Output the top of the PQ as this is the highest amount of occurrences
    cout << amounts.top() << endl;

    return 0;
}
