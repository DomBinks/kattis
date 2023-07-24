#include <bits/stdc++.h>

using namespace std;

void getCosts(int amount, vector<int> &acc, vector<bool> &item, map<int, vector<int>> &comps, 
        map<int, int> &itemToNum)
{
    if(item[amount]) 
    {
        acc.push_back(itemToNum[amount]);
    }
    else
    {
        for(int i : comps[amount])
        {
            getCosts(i, acc, item, comps, itemToNum);
        }
    }

    return;
}

int main()
{
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<bool> item(30001, false);
    map<int, int> itemToNum;

    // Get the number of costs
    int numCosts;
    cin >> numCosts;

    vector<int> costs(numCosts); // Stores each cost

    // For each cost
    for(int i = 0; i < numCosts; i++)
    {
        // At it to the vector of costs
        cin >> costs[i];
        item[costs[i]] = true;
        itemToNum[costs[i]] = i+1;
    }

    vector<bool> ambiguous(30001, false); // Whether this amount is ambiguous
    map<int, vector<int>> comps; // The component amounts used to make this cost
    for(int i = 0; i <= 30000; i++)
    {
        comps[i] = {};
    }
                                 
    // For each cost
    for(int i = 0; i < numCosts; i++)
    {
        int cost = costs[i]; // Get that cost

        // If this amount hasn't been found
        if(comps[cost].empty())
        {
            comps[cost].push_back(cost);
        }
        // If this amount has been found
        else
        {
            // Set this amount to be ambiguous
            ambiguous[cost] = true;
        }

        // For each possible amount that can be expanded upon by this cost
        // (stopping after checking the max amount found so far)
        for(int j = 0; j <= 30000-cost; j++)
        {
            // If this amount has been found and can be expanded upon
            if(comps[j].begin() != comps[j].end())
            {
                // If this amount is ambiguous
                if(ambiguous[j])
                {
                    // Set the amount possible by expanding on this amount
                    // to ambiguous
                    ambiguous[j+cost] = true;
                }
                // If this amount isn't ambiguous
                else
                {
                    // If the amount possible by expanding on this amount
                    // isn't already ambiguous
                    if(!ambiguous[j+cost])
                    {
                        // If the amount possible by expanding on this amount
                        // hasn't already been found
                        if(comps[j+cost].empty())
                        {
                            // Add the amount j to the component amounts of
                            // j+cost
                            comps[j+cost].push_back(j);
                            // Add the amount cost to the component amounts of
                            // j+cost
                            comps[j+cost].push_back(cost);
                        }
                        // If the amount possible by expanding on this amount
                        // has already been found
                        else
                        {
                            // This amount is now ambiguous
                            ambiguous[j+cost] = true;
                        }
                    }
                }
            }
        }
    }

    // Get the number of orders
    int orders;
    cin >> orders;

    // For each order
    for(int i = 0; i < orders; i++)
    {
        // Get the order
        int order;
        cin >> order;

        if(comps[order].empty())
        {
            cout << "Impossible" << endl;
        }
        else if(ambiguous[order])
        {
            cout << "Ambiguous" << endl;
        }
        else
        {
            // Check that all the components of this amount aren't
            // ambiguous
            bool broken = false;
            for(int i : comps[order])
            {
                if(ambiguous[i])
                {
                    cout << i << "Ambiguous" << endl;
                    broken = true;
                    break;
                }
            }
            if(broken)
            {
                continue;
            }

            vector<int> used = {};
            getCosts(order, used, item, comps, itemToNum);
            sort(used.begin(), used.end());

            cout << used[0];
            for(int i = 1; i < used.size(); i++)
            {
                cout << " " << used[i];
            }
            cout << endl;
        }
    }

    return 0;
}
