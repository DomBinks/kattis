#include <iostream>
#include <string>

using namespace std;

int main()
{
    int x, y, n;
    cin >> x >> y >> n;

    for(int i = 1; i <= n; i++)
    {
        string num = "";

        if(i % x == 0)
        {
            num.append("Fizz");
        }

        if(i % y == 0)
        {
            num.append("Buzz");
        }

        if(num == "")
        {
            cout << i << endl;
        }
        else
        {
            cout << num << endl;
        }
    }

    return 0;
}
