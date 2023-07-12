#include <iostream>
#include <map>
#include <vector>
#include <tuple>
#include <queue>
#include <algorithm>

using namespace std;

// Function for comparing 2 pairs of ints, returning whether
// a is before b lexicographically
bool compare(const pair<int,int> &a, const pair<int,int> &b)
{
    if(a.first != b.first)
    {
        return a.first < b.first;
    }
    else
    {
        return a.second < b.second;
    }
}


// Uses prims algorithm to find the minimum spanning tree
int main()
{
    // Keep getting cases
    while(true)
    {
        int n, m;
        cin >> n >> m;

        // If the end pattern is seen
        if(n == m && m == 0)
        {
            // End the program
            break;
        }

        // Initialise a map to store all a node's edges
        map<int, vector<tuple<int,int,int>>> nodeToEdges;
        for(int i = 0; i < n; i++)
        {
            nodeToEdges[i] = {};
        }

        // For each edge
        for(int i = 0; i < m; i++)
        {
            // Get the edge
            int u, v, w;
            cin >> u >> v >> w;

            // Add the edge to the list of edges for both nodes,
            // with the weight being the first item to make sorting easy
            // (flipped to input order)
            nodeToEdges[u].push_back(make_tuple(w, v, u));
            nodeToEdges[v].push_back(make_tuple(w, u, v));
        }

        // Initialise an array and int to track the nodes found so far,
        // starting with only having found node 0
        bool found[n];
        int numFound = 1;
        found[0] = true;
        for(int i = 1; i < n; i++)
        {
            found[i] = false;
        }

        // Initialise a priority queue to store the edges of the currently found
        // nodes that haven't been checked yet, in ascending order of weight
        priority_queue<tuple<int,int,int>, vector<tuple<int, int, int>>, greater<tuple<int,int,int>>> edges;
        for(tuple<int,int,int> edge : nodeToEdges[0])
        {
            edges.push(edge);
        }

        // Initialise an int and vector to store the total weight of the tree
        // and the edges in the tree
        int outputWeight = 0;
        vector<pair<int,int>> outputEdges;

        // While we haven't constructed a spanning tree and have edges left to check
        while(numFound < n && !edges.empty())
        {
            // Get the edge with a minimum weight from a node we've found
            tuple<int,int,int> top = edges.top();
            edges.pop();

            // If it goes to a node we haven't found
            if(!found[get<1>(top)])
            {
                outputWeight += get<0>(top); // Add the edge weight to the total
                found[get<1>(top)] = true; // Set the destination node to found
                numFound++; // Increment the number of nodes found
                int l = get<2>(top); // Get the left node of the edge
                int r = get<1>(top); // Get the right node of the edge
            
                // Add the nodes as an edge to the output vector, with the min
                // node on the left and max node on the right
                outputEdges.push_back(make_pair(min(l, r), max(l, r)));

                // Add all the destination node's edges to the PQ
                for(tuple<int,int,int> edge : nodeToEdges[get<1>(top)])
                {
                    // Check to ensure that the node this specific edge leads
                    // to hasn't been found yet
                    if(!found[get<1>(edge)])
                    {
                        edges.push(edge);
                    }
                }
            }
        }

        // If the tree constructed isn't spanning
        if(numFound < n)
        {
            cout << "Impossible" << endl;
        }
        // If the tree constructed is spanning
        else
        {
            // Sort the output vector so the edges are in lexicographic order
            sort(outputEdges.begin(), outputEdges.end(), compare);

            // Output the total weight of the tree
            cout << outputWeight << endl;

            // Output each node in the tree
            for(pair<int,int> edge : outputEdges)
            {
                cout << edge.first << " " << edge.second << endl;
            }
        }
    }

    return 0;
}
