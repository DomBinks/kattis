#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    map<int, int> occurrences;

    for(int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        occurrences[num]++;
    }

    int max;
    vector<int> maxes;
    while(K >= 0)
    {
        max = 0;
        maxes.clear();
        for(map<int, int>::iterator j = occurrences.begin(); j != occurrences.end(); j++)
        {
            if(j->second > max)
            {
                max = j->second;
                maxes.clear();
                maxes.push_back(j->first);
            }
            else if(j->second == max)
                maxes.push_back(j->first);
        }

        if(K >= maxes.size())
        {
            for(vector<int>::iterator k = maxes.begin(); k != maxes.end(); k++)
            {
                occurrences[*k]--;
            }
        }

        K -= maxes.size();
    }

    cout << max << endl;
    return 0;
}
