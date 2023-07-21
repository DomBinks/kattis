#include <bits/stdc++.h>

using namespace std;

// Calculate the greatest common divisor of a and b
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    // Fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Get the numbers
    long long a, b, c, d;
    cin >> a >> b >> c >> d;

    // Get the GCD of c and d
    long long m = (c * d) / gcd(c, d);

    // Work out how many m's before and including b and remove all the m's
    // before and including a, adding an extra if there is an exact amount of
    // m's in a
    cout << (b / m) - (a / m) + (a % m == 0 ? 1 : 0)<< endl;

    return 0;
}
