#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <tuple>
#include <queue>

using namespace std;

// Comparator class for putting pairs into the priority queue
class Compare {
public:
    bool operator()(pair<int, tuple<int, int, int, int>> a, pair<int, tuple<int, int, int, int>> b)
    {
        // If the number of problems solved is the same
        if(get<0>(a.second) == get<0>(b.second))
        {
            // If the time penalty is the same
            if(get<1>(a.second) == get<1>(b.second))
            {
                // Has a submited their last solution after b
                return get<2>(a.second) > get<2>(b.second);
            }
            // If the time penalty is different
            else
            {
                // Does a have a larger time penalty than b
                return get<1>(a.second) > get<1>(b.second);
            }
        }
        // If the number of problems solved is different
        else
        {
            // Has a solved less problems than b
            return get<0>(a.second) < get<0>(b.second);
        }
    }
};


int main()
{
    // Maps the rank to the score given
    map<int, int> rankToScore = {
        {1, 100},{2, 75},{3, 60},{4, 50},{5, 45},{6, 40},{7, 36},{8, 32},{9, 29}, {10, 26},
        {11, 24},{12, 22},{13, 20},{14, 18},{15, 16},{16, 15},{17, 14},{18, 13},{19, 12}, {20, 11},
        {21, 10},{22, 9},{23, 8},{24, 7},{25, 6},{26, 5},{27, 4},{28, 3},{29, 2}, {30, 1}
    };

    // Stores the contestants in order of best to worst
    priority_queue<pair<int, tuple<int, int, int, int>>, 
        vector<pair<int, tuple<int, int, int, int>>>,
        Compare> pq;

    // Maps the contestant to their score
    map<int, int> contestantToScore;

    // Get the number of contestants
    int n;
    cin >> n;

    // For each contestant
    for(int i = 0; i < n; i++)
    {
        // Get their information
        int s, p, f, o;
        cin >> s >> p >> f >> o;

        // Add them into the PQ, with i as their identifier, with the tuple
        // storing their information
        pq.push(make_pair(i, make_tuple(s, p, f, o)));
    }

    // Start at rank 1
    int rank = 1;

    // While there are contestants left to give a score to
    while(!pq.empty())
    {
        // Get the next contestant
        pair<int, tuple<int, int, int, int>> p = pq.top();
        pq.pop();

        // If this contestant is tied with the next contestant
        if(
            !pq.empty() && 
            get<0>(p.second) == get<0>(pq.top().second) &&
            get<1>(p.second) == get<1>(pq.top().second) &&
            get<2>(p.second) == get<2>(pq.top().second)
        )
        {
            // Store the tied contestants
            vector<pair<int, tuple<int, int, int, int>>> ps;
            ps.push_back(p); // Add this contestant

            // While the next contestant is tied
            while(
                !pq.empty() && 
                get<0>(p.second) == get<0>(pq.top().second) &&
                get<1>(p.second) == get<1>(pq.top().second) &&
                get<2>(p.second) == get<2>(pq.top().second)
            )
            {
                p = pq.top(); // Get the contestant
                pq.pop();
                ps.push_back(p); // Add the contestant to the vector
            }

            int rankScores = 0; // Store the sum of the scores for the ranks
            for(int i = 0; i < ps.size(); i++)
            {
                // While the rank is a valid rank
                if(rank <= 30)
                {
                    // Add that rank's score to the total
                    rankScores += rankToScore[rank];
                    rank++; // Get the next rank
                }
            }

            // Divide the rank by the number of tied contestants, rounding up
            rankScores = (rankScores + ps.size() - 1) / ps.size();

            // Set each tied contestants score to the split rank score +
            // any extra points
            for(int i = 0; i < ps.size(); i++)
            {
                contestantToScore[ps[i].first] = rankScores+get<3>(ps[i].second);
            }
        }
        // If the contestant isn't tied
        else
        {
            // If the contestant is in the top 30
            if(rank <= 30)
            {
                // Set their score to be the score for the current rank +
                // their extra point if applicable
                contestantToScore[p.first] = rankToScore[rank]+get<3>(p.second);

                // Go to the next rank
                rank++;
            }
            // If the contestant isn't in the top 30
            else
            {
                // Set their score to be their extra point if applicable
                contestantToScore[p.first] = get<3>(p.second);
            }
        }
    }

    // Print out each contestant's score
    for(int i = 0; i < n; i++)
    {
        cout << contestantToScore[i] << endl;
    }

    return 0;
}
