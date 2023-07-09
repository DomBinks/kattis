#include <iostream>

using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    int x[41];
    for(int i = 0; i < 41; i++)
    {
        x[i] = 0;
    }

    int upper = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            x[i+j]++;
            upper = x[i+j] >= upper ? x[i+j] : upper;
        }
    }

    for(int i = 1; i < 41; i++)
    {
        if(x[i] == upper)
        {
            cout << i << endl;
        }
    }

    return 0;
}
