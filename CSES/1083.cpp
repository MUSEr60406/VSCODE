//Missing Number
#include<iostream>
#define ll long long
using namespace std;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    ll n, sum = 0;
    cin >>  n;
    for(int i = 1 ; i <= n ; i++)
        sum += i;
    for(int i = 0 ; i < n - 1 ; i++)
    {
        int m;
        cin >> m;
        sum -= m;
    }
    cout << sum;
    return 0;
}