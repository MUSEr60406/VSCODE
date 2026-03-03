#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    while(cin >> n && n != 0)
    {
        while(true)
        {
            vector<int> test(n);
            cin >> test[0];
            if(test[0] == 0)
            {
                cout << "\n";
                break;
            }
            for(int i = 1 ; i < n ; i++)
                cin >> test[i];
            stack<int> station;
            int index = 0;
            for(int i = 1 ; i <= n ; i++)
            {
                station.push(i);
                while(!station.empty() && station.top() == test[index])
                {
                    station.pop();
                    index++;
                }
            }
            if(station.empty())
                cout << "Yes\n";
            else
                cout << "No\n";
        }
    }

    return 0;
}