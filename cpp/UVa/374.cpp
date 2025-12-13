#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
ll bigmod(ll b, ll p, ll m)
{
    ll ans = 1;
    b %= m; 
    while(p > 0)
    {
        if(p & 1)
            ans = (ans * b) % m;
        b = (b * b) % m;
        p >>= 1;
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll b, p, m;
    while(cin >> b >> p >> m)
        cout << bigmod(b, p, m) << "\n";

    return 0;
}