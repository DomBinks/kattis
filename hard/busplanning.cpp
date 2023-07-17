#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <queue>

using namespace std;

int main()
{
    int n, k, c;
    cin >> n >> k >> c;

    vector<string> names(n);
    for(string &n : names)
    {
        cin >> n;
    }

    map<string, vector<string>> dislikes;
    for(string name : names)
    {
        dislikes[name] = {};
    }

    for(int i = 0; i < k; i++)
    {
        string a, b;
        cin >> a >> b;

        dislikes[a].push_back(b);
        dislikes[b].push_back(a);
    }

    priority_queue<pair<int, string>> pq;
    for(string name : names)
    {
        pq.push(make_pair(dislikes[name].size(), name));
    }

    vector<vector<string>> buses;
    buses.push_back({});
    while(!pq.empty()) 
    {
        string x = pq.top().second;
        pq.pop();
        bool set = false;

        for(vector<string> &bus : buses)
        {
            bool happy = true;

            if(bus.size() == c)
            {
                continue;
            }

            for(string d : dislikes[x])
            {
                if(find(bus.begin(), bus.end(), d) != bus.end())
                {
                    happy = false;
                    break;
                }
            }
            
            if(happy)
            {
                bus.push_back(x);
                set = true;
                break;
            }
        }

        if(!set)
        {
            buses.push_back({x});
        }
    }

    cout << buses.size() << endl;
    for(vector<string> bus : buses)
    {
        cout << bus[0];
        for(int i = 1; i < bus.size(); i++)
        {
            cout << " " << bus[i];
        }
        cout << endl;
    }

    return 0;
}
