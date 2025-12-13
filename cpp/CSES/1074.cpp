#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
int main()
{
    ll n, ans = 0;
    cin >> n;
    vector<ll> L(n);
    for(int i = 0 ; i < n ; i++)
        cin >> L[i];

    sort(L.begin(), L.end());

    ll mid = n/2;
    for(int i : L)
        ans += abs(i - L[mid]);
    
    cout << ans;
    return 0;
}