#include <iostream>
using namespace std;

int main()
{
    // Get input
    int N, M;
    cin >> N >> M;

    // How many big lines to print
    int big = M % N;
    
    // For each big line to print
    for (int i = 0; i < big; i++)
    {
        // Print a * for the ceiling of the number per line
        for (int j = 0; j < (M + (N - 1)) / N; j++)
        {
            cout << '*';
        }
        cout << endl;
    }

    // How many small lines to print
    int small = N - big;

    // For each small line to print
    for (int i = 0; i < small; i++)
    {
        // Print a * for the floor of the number per line
        for (int j = 0; j < M / N; j++)
        {
            cout << '*';
        }
        cout << endl;
    }

    return 0;
}
