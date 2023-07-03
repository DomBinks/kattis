#include <iostream>
#include <string>

using namespace std;

int main()
{
	// Get inputs
	string one, two;
	cin >> one >> two;
	// Check to see if the first is longer than the second
	one.size() >= two.size() ? cout << "go" << endl : cout << "no" << endl;

	return 0;
}
