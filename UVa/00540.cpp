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
        queue<int> team[1005];
        bool exit[1005] = {false};
        int no_team = t;
;       for(int i = 0 ; i < t ; i++)
        {
            int n;
            cin >> n;
            for(int j = 0 ; j < n ; j++)
            {
                int value;
                cin >> value;
                m.insert({value, i});
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
                    {
                        team_order.push(m[number]);
                        exit[m[number]] = true;
                    }
                }
                else
                {
                    team[no_team].push(number);
                    if(!exit[no_team])
                        team_order.push(no_team);
                    no_team++;
                }
            }
            else if(command == "DEQUEUE")
            {
                cout << team[team_order.front()].front() << "\n";
                team[team_order.front()].pop();
                if(team[team_order.front()].empty())
                {
                    exit[team_order.front()] = false;
                    team_order.pop();
                }   
            }
        }
        cout << "\n";
    }
    return 0;
}