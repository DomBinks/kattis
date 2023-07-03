#include <iostream>

using namespace std;

int main()
{
	// Get number of test cases
	int t;
	cin >> t;
	
	// For each test case
	while(t-- > 0)
	{
		// Get the number of cards
		int n;
		cin >> n;

		// If there is only 1 card
		if(n == 1)
		{
			cout << "1" << endl;
			continue;
		}

		// Create a list to store the cards in
		// (treated as a circular list)
		int *list = new int[n];
		for(int i = 0; i < n; i++)
		{
			list[i] = -1;
		}

		// Set the position of 1 as it's always here
		list[1] = 1;

		int index = 1;
		int m = 2;
		// While the card to insert isn't greater than the number of cards to insert
		while(m <= n)
		{
			int hops = 0; // Number of cards put to the back of the deck
			while (hops <= m) // <= as want to put m cards to the back of the deck
			{
				index = (index + 1) % n; // Go to the next index

				// If that index doesn't contain a card that has already been
				// pulled out the deck
				if(list[index] == -1)
				{
					// Increment the number of cards put to the back of the deck
					hops++;
				}
				// Only deals with cards that are still in the deck
				// If a card has been placed at an index it represents a card
				// that has been dealt from the deck
			}

			// Place the card in the list
			list[index] = m;
			m++;
		}

		// Print the list
		cout << list[0];
		for(int i = 1; i < n; i++)
		{
			cout << " " << list[i];
		}
		cout << endl;
	}

	return 0;
}
