#include <iostream>
#include <string>

using namespace std;

int main()
{
    // Get inputs
    string ann, ben; 
    cin >> ann >> ben;

    // Pointer to position within ann and ben
    int a = 0;
    int b = 0;

    // Store output string
    string out = "";

    // As ann and ben are sorted, they can be merged together using the merge
    // from merge sort

    // While the end of either string hasn't been reached
    while(a < ann.length() and b < ben.length())
    {
        if(ann[a] < ben[b])
        {
            out.append(ann.substr(a, 1));
            a++;
        }
        else
        {
            out.append(ben.substr(b, 1));
            b++;
        }
    }

    // While there are characters left in ann
    while(a < ann.length())
    {
        out.append(ann.substr(a,1));
        a++;
    }

    // While there are characters left in ben
    while(b < ben.length())
    {
        out.append(ben.substr(b,1));
        b++;
    }

    cout << out << endl;

    return 0;
}
