#include <iostream>

using namespace std;

int main()
{
    int k, m, n;
    cin >> k >> m >> n;

    cout << (k % (m+n) < m ? "Barb" : "Alex") << endl;

    return 0;
}
