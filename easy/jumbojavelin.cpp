#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;
    
    int total = 1 - n;
    while(n-- > 0)
    {
        int l;
        cin >> l;
        total += l;
    }
    
    cout << total << endl;
    
    return 0;
}