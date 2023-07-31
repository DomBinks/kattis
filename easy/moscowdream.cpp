#include <bits/stdc++.h>

using namespace std;

int main()
{
    int a, b, c, n;
    cin >> a >> b >> c >> n;

    cout << (a > 0 && b > 0 && c > 0 && a+b+c >= n && n >= 3 ? "YES" : "NO") << endl;

    return 0;
}
