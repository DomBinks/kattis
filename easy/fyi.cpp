#include <iostream>
using namespace std;

int main()
{
    int num;
    cin >> num;

    int out;
    out = (num >= 5550000) && (num < 5560000) ? 1 : 0;

    cout << out << endl;
    return 0;
}
