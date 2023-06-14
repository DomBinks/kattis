#include <iostream>
#include <algorithm>
#include <map>
#include <list>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    int max = 1000000001;

    int N, Q;
    cin >> N >> Q;

    map<int, int> seen;

    for(int i = 0; i < N; i++)
    {
        int D;
        cin >> D;

        if(seen.find(D) == seen.end())
        {
            seen[D] = 1;
        }
        else
        {
            seen[D] += 1;
        }
    }
    
    for(int i = 0; i < Q; i++)
    {
        int T, D;
        cin >> T >> D;

        if(T == 1)
        {
            map<int, int>::iterator it = upper_bound(seen.begin(), seen.end(), D);

            while(it != seen.end())
            {
                if(it->second > 0)
                {
                    it->second--;
                    break;
                }
                else
                {
                    it++;
                }
            }

            if(it == seen.end())
            {
                cout << -1 << endl;
            }
            else
            {
                cout << it->second << endl;
            }
        }

        if(T == 2)
        {
            map<int, int>::iterator it = lower_bound(seen.begin(), seen.end(), D);

            bool found = false;

            while(it != seen.begin())
            {
                if(it->second > 0)
                {
                    it->second--;
                    found = true;
                    break;
                }
                else
                {
                    it--; 
                }
            }

            if(it == seen.begin() && it->second > 0)
            {
                it->second--;
                found = true;
            }

            if(found)
            {
                cout << it->second << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }

    return 0;
}
