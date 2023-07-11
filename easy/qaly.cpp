#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    double total = 0;
    
    while(n-->0)
    {
        double q, y;
        cin >> q >> y;
        
        total += (q * y);
    }
    
    cout << total << endl;
    
    return 0;
}