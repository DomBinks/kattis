#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Get the number of children and throws
    int n, k;
    cin >> n >> k;

    vector<int> t; // Stores the throws

    // While there is a throw to get
    while(k-- > 0)
    {
        // Get the throw
        string s;
        cin >> s;

        // If throws need to be undone
        if(s == "undo")
        {
            // Get the amount to undo
            int a;
            cin >> a;

            // Remove that many throws from the end of the vector
            while(a-- > 0 && t.size() > 0)
            {
                t.erase(t.begin()+t.size()-1);
            }
        }
        // If it's a throw
        else
        {
            // Add it to the vector of throws
            t.push_back(stoi(s));
        }
    }

    int c = 0; // Tracks the current child

    // For each throw
    for(int i : t)
    {
        c += i; // Add the throw to the current child

        // If the upper bound is exceeded
        while(c >= n)
        {
            // Bring the current child back in bounds
            c -= n;
        }

        // If the lower bound is exceeded
        while(c < 0)
        {
            // Bring the current child back in bounds
            c += n;
        }
    }

    cout << c << endl;

    return 0;
}
