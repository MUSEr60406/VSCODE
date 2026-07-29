#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
vector<ll> ch(200000);
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, x, ans = 0;
    cin >> n >> x;
    for(int i = 0 ; i < n ; i++)
        cin >> ch[i];
    sort(ch.begin(), ch.end());
    int l = 0, r = n - 1;
    while(l <= r)
    {
        if(l == r)
        {
            ans++;
            break;
        }
        if(ch[l] + ch[r] <= x)
        {
            ans++;
            l++;
            r--;
        }
        else
        {
            ans++;
            r--;
        }
    }
    cout << ans << "\n";
    return 0;
}