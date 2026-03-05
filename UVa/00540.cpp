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
                if(m.find(number) != m.end())
                {
                    int index = -1;
                    for(int i = 0; i < q.size() ; i++)
                        if(m.find(q[i]) == m.end())
                            index = i;
                    if(index == -1)
                        q.push_back(number);
                    else
                        q.insert(q.begin() + index, number);
                }
                else
                    q.push_back(number);
                for(auto i : q)
                    cout << i << " ";
                cout << "\n";
            }
            else if(command == "DEQUEUE")
            {
                //cout << q[0] << "\n";
                q.erase(q.begin());
            }
        }
    }
    return 0;
}