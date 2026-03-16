#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
#define pb push_back
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    while(cin >> n && n != 0)
    {
        int t = 0;
        string s;
        vector<vector<int>> g(n + 1);
        vector<int> ids(n + 1, -1);
        vector<int> low(n + 1); //low-link
        cin.ignore();
        while(getline(cin, s))
        {
            if(s == "0")
                break;
            int now = s[0] - '0';
            for(int i = 2 ; i < s.size() ; i++)
            {
                if(s[i] == ' ') 
                    continue;
                g[now].pb(s[i] - '0');
                g[s[i] - '0'].pb(now);
            }
        }
        
    }

    return 0;
}