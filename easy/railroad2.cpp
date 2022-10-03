#include <iostream>
using namespace std;

int main()
{
    int xs, ys; // Store number of x pieces and y pieces
    cin >> xs >> ys;
    int count = (xs * 4) + (ys * 3); // Number of ends of track
    
    // If the number of ends of track isn't divisible by 2 then it means that
    // it won't be a closed track as all the ends can't be paired up
    cout << (count % 2 == 0 ? "possible" : "impossible") << endl;

    return 0;
}
