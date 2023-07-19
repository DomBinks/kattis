#include <iostream>
#include <vector>
#include <math.h>
#include <algorithm>

using namespace std;

int main()
{
    // Get the max a size
    int n;
    cin >> n;

    // Get the number of the max a size possible needed to create the a1 paper
    int numMaxNeeded = 2 * pow(2, n-2);

    // Whether that specific amount of the max a size has been found
    bool *found = new bool[numMaxNeeded+1];
    
    // The pieces of paper needed to make that specific amount of the max a size
    // (size of inner vector is the number of pieces of paper)
    vector<vector<int>> pieces(numMaxNeeded+1);

    // Setup the array and vector to track the sizes found and the pieces used
    // for each size
    for(int i = 0; i <= numMaxNeeded; i++)
    {
        found[i] = false;
        pieces[i] = {};
    }
    found[0] = true;

    // For each size of paper
    for(int i = 2; i <= n; i++)
    {
        // Get the amount of pieces that size
        int numSizeI;
        cin >> numSizeI;

        // Stores the possible additions to pieces (i.e. new possible sizes)
        vector<pair<int, vector<int>>> possible;
        
        // For each amount of those pieces that could be used
        // No greater than 2^n-1 as that's the number of pieces needed of this
        // size to create an a1 sheet
        for(int j = 1; j <= min(numSizeI, static_cast<int>(pow(2, n-1))); j++)
        {
            // Convert these pieces into the number of pieces of max a size
            int numMaxSize = j * pow(2, n-i);

            // For each possible existing size that could've been created
            // previously, and could be expanded upon with these new pieces
            // while staying within the range of numMaxNeeded
            for(int k = numMaxNeeded - numMaxSize; k >= 0; k--)
            {
                // If that size as been constructed already
                if(found[k])
                {
                    // Stores the new pieces for the new size
                    vector<int> newPieces;

                    // Add all the pieces to get size k
                    for(int x : pieces[k])
                    {
                        newPieces.push_back(x);
                    }
                    // Add all the new pieces to get size +numMaxSize
                    for(int x = 0; x < j; x++)
                    {
                        newPieces.push_back(i);
                    }

                    // Add this size and the pieces to the list of possible additions
                    possible.push_back(make_pair(k+numMaxSize, newPieces)); 
                }
            }
        }

        // For each new possible addition
        for(pair<int, vector<int>> p : possible)
        {
            // If this size has already been found
            if(found[p.first])
            {
                // If this set of pages is smaller
                if(p.second.size() < pieces[p.first].size())
                {
                    // Clear the pieces to make this size
                    pieces[p.first].clear();

                    // Add each piece to the vector of pieces
                    for(int x : p.second)
                    {
                        pieces[p.first].push_back(x);
                    }
                }
            }
            // If this new size hasn't already been found
            else
            {
                found[p.first] = true; // Set this size to found

                // Add each piece to the vector of pieces
                for(int x : p.second)
                {
                    pieces[p.first].push_back(x);
                }
            }
        }
    }

    // If there is the exact pieces needed to create an A1 piece of paper
    if(found[numMaxNeeded])
    {
        double total = 0.0; // Stores the total of the tape needed

        // Setup an array to store the number of each size of paper
        int left[n+1];
        for(int i = 0; i <= n; i++)
        {
            left[i] = 0;
        }

        // Put each piece used into the array
        for(int p : pieces[numMaxNeeded])
        {
            left[p]++;
        }

        // Decrement through each possile paper size
        while(n >= 2)
        {
            // If there are no sheets of this size
            if(left[n] == 0)
            {
                // Go to the next size
                n--;
            }
            // If there are sheets of this size
            else
            {
                // If the size is even
                if(n % 2 == 0)
                {
                    // Add the amount of tape required to tape 2 pieces of this
                    // size together
                    total += pow(2, -(((n/2)*4 - 1) / 4.0));
                }
                // If the size is odd
                else
                {
                    // Add the amount of tape required to tape 2 pieces of this
                    // size together
                    total += pow(2, -(((n/2)*4 + 1) / 4.0));
                }

                // Increment the number of sheets with a smaller a size as a new
                // sheet has been created
                left[n-1]++;
                left[n] -= 2; // Decrement the number of this size by 2
            }
        }

        // Print the total amount of tape used
        printf("%0.11f\n", total);
    }
    // If there isn't the exact pieces needed to create an A1 piece of paper
    else
    {
        cout << "impossible" << endl;
    }

    return 0;
}
