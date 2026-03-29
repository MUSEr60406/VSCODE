#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
vector<string> g;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        int m, n;
        cin >> m >> n;
        g.clear();
        g.resize(m);  
        for(string &s : g)
        {
            cin >> s;
            for(char &c : s)
                c = tolower(c);
        }
        int k;
        cin >> k;
        for(int i = 0 ; i < k ; i++)
        {
            string s;
            cin >> s;
            for(char &c : s)
                c = tolower(c);
        }
    }

    return 0;
}