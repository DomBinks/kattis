#include <iostream>
#include <utility>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool cmp(pair<int,int>& a, pair<int,int>& b)
{
    return a.second < b.second;
}

int main()
{
    int n;
    cin >> n;

    vector<pair<int, int>> overlap;
    for(int i = 0; i < 2*n + 1; i++)
    {
        overlap.push_back(make_pair(i, 0));
    }

    vector<pair<int, int>> minions;
    for(int i = 0; i < n; i++)
    {
        int l, u;
        cin >> l >> u;
        minions.push_back(make_pair(l, u));

        for(int j = l; j <= u; j++)
        {
            overlap[j].second++;
        }
    }
    cout << "---------------------" << endl;

    sort(overlap.begin(), overlap.end(), cmp);
    reverse(overlap.begin(), overlap.end());
    for(int i = 0; i < 2*n + 1; i++)
    {
        cout << overlap[i].first << " " << overlap[i].second << endl;
    }

    int rooms = 0;

    while(minions.begin() != minions.end())
    {
        bool roomIncr = false;
        cout << "Rooms: " << rooms << endl;

        vector<pair<int,int>>::iterator current = minions.begin();

        int temp = (*overlap.begin()).first;
        overlap.erase(overlap.begin());
        cout << "Temp: " << temp << endl;

        while(current != minions.end())
        {
            cout << "Current: " << (*current).first << " " << (*current).second << endl; 
            if(temp >= current->first && temp <= current->second)
            {
                if(!roomIncr)
                {
                    rooms++;
                    roomIncr = true;
                }
                cout << "Removing " << current->first << " " << current->second << endl;
                minions.erase(current);
                cout << "Current now: " << (*current).first << " " << (*current).second << endl; 
            }
            else
            {
                current++;
            }
        }
    }

    cout << rooms << endl;
    return 0;
}
