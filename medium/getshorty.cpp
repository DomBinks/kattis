#include <bits/stdc++.h>

using namespace std;

int main()
{
    while(true)
    {
        // Get number of nodes and paths
        int n, m;
        cin >> n >> m;

        if(n == m && m == 0)
        {
            break;
        }

        // Set up a map to store each node's paths
        map<int, vector<pair<float, int>>> paths;
        for(int i = 0; i < n; i++)
        {
            paths[i] = {};
        }
        
        // Get each path
        for(int i = 0; i < m; i++)
        {
            int u, v;
            float w;
            cin >> u >> v >> w;

            // Assign both directions to the list of paths for both nodes
            paths[u].push_back(make_pair(w, v));
            paths[v].push_back(make_pair(w, u));
        }

        // Set up an array to store the cost to each node from 0
        float cost[n];
        for(int i = 0; i < n; i++)
        {
            cost[i] = 0;
        }

        // Set up an array to store whether a node has been seen yet
        bool seen[n];
        for(int i = 0; i < n; i++)
        {
            seen[i] = false;
        }
        seen[0] = true;

        // Set up priority queue to store the distance to nodes
        priority_queue<pair<float, int>> pq;
        pq.push(make_pair(1, 0));

        // While there are still nodes to investigate
        while(!pq.empty())
        {
            // Get the node
            pair<float, int> top = pq.top();
            pq.pop();
            
            // Update the cost to this node if it's higher
            cost[top.second] = max(top.first, cost[top.second]);

            // Set this node to be seen
            seen[top.second] = true;

            // For each path from this node
            for(pair<float, int> path : paths[top.second])
            {
                // If the destination node hasn't been seen yet
                if(!seen[path.second])
                {
                    // Add that node to the PQ, with the weight being the weight
                    // to this node * the weight of the path to the destination node
                    pq.push(make_pair(path.first*top.first, path.second));
                }
            }
        }

        printf("%0.4f\n", cost[n-1]);
    }

    return 0;
}
