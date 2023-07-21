#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    while(n-- > 0)
    {
        int k;
        cin >> k;
        cout << k << " ";
        cin >> k;
        
        cout << (k * (k+1) / 2) + k << endl;
    }
    
    return 0;
}