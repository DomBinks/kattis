#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    while(N-- > 0)
    {
        int K;
        cin >> K;
        int sum = 0;
        for(int i = 0; i < K; i++)
        {
            int bar;
            cin >> bar;
            sum += bar;
        }

        cout << sum - K + 1 << endl;
    }

    return 0;
}
