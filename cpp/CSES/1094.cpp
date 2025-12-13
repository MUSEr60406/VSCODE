//Increasing Array
#include<iostream>
#define ll long long
using namespace std;
int main()
{
    ll n, ans = 0, last = 0 , now = 0;
    cin >> n;
    for(ll i = 0 ; i < n ; i++)
    {
        cin >> now;
        if(i == 0)
            last = now;
        else if(now < last)
            ans += (last - now);
        else
            last = now;
    }
    cout << ans;
    return 0;
}