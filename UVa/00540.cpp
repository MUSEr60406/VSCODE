#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    while(cin >> t && t != 0)
    {
        map<int, int> m;
        for(int i = 0 ; i < t ; i++)
        {
            int n;
            for(int j = 0 ; j < n ; j++)
            {
                int value, team;
                cin >> value >> team;
                m.insert({value, team});
            }
        }
    }

    return 0;
}