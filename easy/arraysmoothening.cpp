#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main()
{
    int N, K;
    cin >> N >> K;
    map<int, int> occurrences;
    int output;

    for(int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        occurrences[num]++;
    }

    while(K >= 0)
    {
        int max = 0;
        for(map<int, int>::iterator j = occurrences.begin(); j != occurrences.end(); j++)
        {
            if(j->second > occurrences[max])
                max = j->first;
        }

        if(K > 0)
            occurrences[max]--;
        else
            cout << occurrences[max] << endl;

        K--;
    }

    return 0;
}
