#include <iostream>

using namespace std;

int main()
{
	// Get input
	int n;
	cin >> n;

	// While i >= 0 (true)
	for (int i = 0; i >= 0 ; i++)
	{
		int divisor = 0; // Sum of digits
		int m = n + i; // Number whose digits are being summed

		while (m > 0) // While there are digits left
		{
			divisor += (m % 10); // Add the right most digit to the divisor
			m = m / 10; // Remove the rightmost digit
		}

		// If the number is a harshad number
		if ((n + i) % divisor == 0)
		{
			// Output the number
			cout << n + i << endl;
			break; // End
		}
	}

	return 0;
}
