#include <iostream>
#include <string>
using namespace std;

int main()
{
    string input;
    cin >> input;
    cout << input.substr(input.find('a')) << endl;
    return 0;
}
