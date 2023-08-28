#include <bits/stdc++.h>

using namespace std;

// Used to sort pairs based on their first number, followed by their second
bool Compare(pair<int, int> &a, pair<int, int> &b)
{
    if(a.first == b.first)
    {
        return a.second < b.second;
    }
    else
    {
        return a.first < b.first;
    }
}

int main()
{
    vector<pair<int, int>> ps; // Vector of the pieces

    // Get all the pieces
    for(int i = 0; i < 3; i++)
    {
        int a, b;
        cin >> a >> b;
        ps.push_back(make_pair(max(a,b), min(a,b)));
    }

    // Sort the pieces in descending order
    sort(ps.begin(), ps.end());
    reverse(ps.begin(), ps.end());

    // Store the piece with the longest side in m, and the 2 smaller pieces
    // in a and b
    pair<int, int> m = *ps.begin();
    pair<int, int> a = *(ps.begin()+1);
    pair<int, int> b = *(ps.begin()+2);

    // Get the long and short side of the piece with the longest side
    int l = max(m.first, m.second);
    int s = min(m.first, m.second);

    // If the sum pairs of side lengths for the vertical and horizontal sides of the other 2 pieces
    // aren't equal to the longest side of m, or pair of side lengths aren't both equal to the longest side of m
    if(a.first + b.first != l && a.second + b.second != l && (a.first != m.first && b.first != m.first))
    {
        // Switch the vertical and horizontal sides of piece a
        int t = a.first;
        a.first = a.second;
        a.second = t;
    }

    int d; // The amount to add to the shortest side to get towards l

    // If the longest side of a and b are equal to l
    if(a.first == b.first && b.first == l)
    {
        // The amount to add is the sum of their shorter sides
        d = a.second + b.second;
    }
    // If the first sides of a and b are equal to l and the other sides are the same length
    else if(a.first + b.first == l && a.second == b.second)
    {
        // The amount to add is the other side length
        d = a.second;
    }
    // If the second sides of a and b are equal to l and the other sides are the same length
    else if(a.second + b.second == l && a.first == b.first)
    {
        // The amount to add is the other side length
        d = a.first;
    }
    // If 2 sides can't be added to get to size l, or the other sides don't match so
    // don't create a rectangle
    else
    {
        cout << "NO" << endl;
        return 0;
    }

    // If you can get to l by adding the amount to the shortest side
    if(l == s+d)
    {
        cout << "YES" << endl;
    }
    // If you can't get to l by adding the amount to the shortest side
    else
    {
        cout << "NO" << endl;
    }

    return 0;
}
