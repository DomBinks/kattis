#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    // Use fast IO
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // Get number of lines of input
    int n;
    cin >> n;

    int timer = 0; // Current time - each event is assigned an int time
    unordered_map<string, int> eventToTime; // Maps events to their time
    vector<string> events; // Order events were added to the map

    // For each line
    while(n-- > 0)
    {
        // Get type of input to deal with
        char t;
        cin >> t;

        // If the input is an event
        if(t == 'E')
        {
            // Get the event
            string event;
            cin >> event;

            // Add the event to the map and vector
            eventToTime[event] = timer;
            events.push_back(event);
            timer++; // Increment the timer
        }
        // If the input is a scenario
        else if(t == 'S')
        {
            // Get the number of events in the scenario
            int k;
            cin >> k;

            int lower = 500002; // Earliest time an event occurs that needs to be removed
            int normal = -1; // Latest time an event that needs to happen occurs
            bool skip = false; // Whether the loop should skip to the next j if there's a plot error
            for(int j = 0; j < k; j++)
            {
                // Get an event
                string event;
                cin >> event;

                // Skip to the next j if necessary
                if(skip)
                {
                    continue;
                }

                // If the event shouldn't happen
                if(event[0] == '!')
                {
                    unordered_map<string, int>::iterator eit = eventToTime.find(event.substr(1, event.length()-1));
                    // If the event does happen
                    if(eit != eventToTime.end())
                    {
                        // Update lower if this event happens earlier than
                        // previous events that shouldn't happen
                        lower = min(lower,eit->second);
                    }
                }
                // If the event should happen
                else
                {
                    unordered_map<string, int>::iterator eit = eventToTime.find(event);

                    // If the event doesn't happen
                    if(eit == eventToTime.end())
                    {
                        // Set skip to true as there is a plot error
                        skip = true;
                        continue;
                    }
                    // If the event does happen
                    else
                    {
                        // Update normal if this event happens later than
                        // previous events that should happen
                        normal = max(normal, eit->second);
                    }
                }
            }

            // If there is a plot error or will be if an event that needs to
            // happen is removed when removing an event that shouldn't happen
            if(skip || normal >= lower)
            {
                cout << "Plot Error" << endl;
            }
            // If there isn't a plot error
            else
            {
                // Get the amount of events that need to be removed
                int diff = timer - lower;

                // If some events need to be removed
                if(diff > 0)
                {
                    cout << timer - lower << " Just A Dream" << endl;
                }
                // If no events need to be removed
                else
                {
                    cout << "Yes" << endl;
                }
            }
        }
        // If the input is a dream
        else
        {
            // Get the number of events to remove
            int r;     
            cin >> r;

            // Remove that many events
            while(r-- > 0)
            {
                string back = events.back(); 
                events.pop_back();
                eventToTime.erase(back);
                timer--; // Decrement the timer as the last event has been removed
            }
        }
    }

    return 0;
}
