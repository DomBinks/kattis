#include <iostream>
#include <list>
#include <algorithm>
#include <map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n, q;
    cin >> n >> q;

    map<string,string> partner;
    list<string> line;

    for(int i = 0; i < n; i++)
    {
        string a, b;
        cin >> a >> b;

        partner[a] = b;
        partner[b] = a;

        line.push_back(a);
        line.push_back(b);
    }
    
    string instructions;
    cin >> instructions;

    list<string>::iterator mic = line.begin();

    for(char inst : instructions)
    {
        if(inst == 'F')
        {
            mic--;
        }
        else if(inst == 'B')
        {
            mic++;
        }
        else if(inst == 'R')
        {
            string person = *mic;
            mic++;
            if(mic == line.end())
            {
                mic = line.begin();
            }
            else
            {
                line.erase(find(line.begin(), line.end(), person));
                line.push_back(person);
            }
        }
        else if(inst == 'C')
        {
            string person = *mic;
            mic++;
            if(mic == line.end())
            {
                mic = line.begin();
            }
            else
            {
                line.erase(find(line.begin(), line.end(), person));
                list<string>::iterator index = find(line.begin(), line.end(),partner[person]);
                index++;
                line.insert(index, person);
            }
        }
        else if(inst == 'P')
        {
            cout << partner[*mic] << endl; 
        }
    }

    cout << endl;
    for(string person : line)
    {
        cout << person << endl;
    }

    return 0;
}
