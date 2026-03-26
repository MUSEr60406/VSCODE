#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
vector<string> g;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int N;
    while(cin >> N)
    {
        g.clear();
        g.resize(N);
        for(auto &s : g)
            cin >> s;
    }

    return 0;
}