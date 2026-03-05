#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t, count = 0;
    while(cin >> t && t != 0)
    {
        cout << "Scenario #" << ++count << "\n";
        map<int, int> m;
        queue<int> team_order;
        queue<int> team[1000];
        bool exit[1000] = {false}
;       for(int i = 0 ; i < t ; i++)
        {
            int n;
            for(int j = 0 ; j < n ; j++)
            {
                int value;
                cin >> value;
                m.insert({value, t});
            }
        }
        string command;
        while(cin >> command && command != "STOP")
        {
            int number;
            if(command == "ENQUEUE")
            {
                cin >> number;
                if(m.find(number) != m.end())
                {
                    team[m[number]].push(number);
                    if(!exit[m[number]])
                        team_order.push(m[number]);
                }
                else
                {
                    team[t].push(number);
                    if(!exit[t])
                        team_order.push(t);
                    t++;
                }
            }
            else if(command == "DEQUEUE")
            {
                
            }
        }
    }
    return 0;
}