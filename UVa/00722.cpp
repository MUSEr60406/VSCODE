#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
int bfs(pii, vector<string> &Map)
{

}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    while(n--)
    {
        cin.ignore();
        pii p;
        vector<string> Map;
        string s;
        cin >> p.first >> p.second;
        while(getline(cin, s))
            Map.push_back(s);
        cout << bfs(p, Map);
    }
    return 0;
}