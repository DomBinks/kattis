#include <iostream>

using namespace std;

int main()
{
    string m, d;
    cin >> m >> d;
    
    cout << ((m == "OCT" && d == "31") || (m == "DEC" && d == "25") ? "yup" : "nope") << endl;
    
    return 0;
}