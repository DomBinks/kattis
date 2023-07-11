#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int total = 0;
    while(n-- > 0)
    {
        int x;
        cin >> x;
        total += x;
    }
    
    cout << total << endl;
    
    return 0;
}