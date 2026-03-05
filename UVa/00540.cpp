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
        queue<int> q;
        queue<int> team[1000];
        bool exit[1005] = {false};
        for(int i = 0 ; i < t ; i++)
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
            }
            else if(command == "DEQUEUE")
            {
            }
        }
    }
    return 0;
}