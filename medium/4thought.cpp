#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Maps a number to the combination of operators string
    map<int, string> comb;

    // Put all possible numbers that can be created into the map
    comb[-60] = "4 - 4 * 4 * 4 = -60";
    comb[-16] = "4 - 4 - 4 * 4 = -16";
    comb[-15] = "4 / 4 - 4 * 4 = -15";
    comb[-8] = "4 + 4 - 4 * 4 = -8";
    comb[-7] = "4 / 4 - 4 - 4 = -7";
    comb[-4] = "4 / 4 / 4 - 4 = -4";
    comb[-1] = "4 - 4 - 4 / 4 = -1";
    comb[0] = "4 * 4 - 4 * 4 = 0";
    comb[1] = "4 - 4 + 4 / 4 = 1";
    comb[2] = "4 / 4 + 4 / 4 = 2";
    comb[4] = "4 + 4 / 4 / 4 = 4";
    comb[7] = "4 + 4 - 4 / 4 = 7";
    comb[8] = "4 + 4 + 4 - 4 = 8";
    comb[9] = "4 + 4 + 4 / 4 = 9";
    comb[15] = "4 * 4 - 4 / 4 = 15";
    comb[16] = "4 + 4 + 4 + 4 = 16";
    comb[17] = "4 * 4 + 4 / 4 = 17";
    comb[24] = "4 + 4 + 4 * 4 = 24";
    comb[32] = "4 * 4 + 4 * 4 = 32";
    comb[60] = "4 * 4 * 4 - 4 = 60";
    comb[68] = "4 + 4 * 4 * 4 = 68";
    comb[256] = "4 * 4 * 4 * 4 = 256";

    // For each case
    int t;
    cin >> t;
    int current;
    while(t-- > 0)
    {
        // Get the target number
        cin >> current;

        // Print the combination if it's in the map
        cout << (comb.count(current) > 0 ? comb[current] : "no solution") << endl;
    }

    return 0;
}
