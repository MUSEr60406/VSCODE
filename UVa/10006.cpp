#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
ll biEx(ll base, ll p, ll mod)
{
    ll res = 1;
    base %= mod;
    while(p > 0)
    {
        if(p & 1)
         res = (res * base) % mod;
         base = (base * base) % mod;
         p >>= 1;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<bool> isprime(65001, true);
    vector<int> prime;
    for(int i = 2 ; i <= 65000 ; i++)
    {
        if(isprime[i])
            prime.push_back(i);
        for(int &j : prime)
        {
            if(i * j > 65000)
                break;
            isprime[i * j] = false;
            if(i % j == 0)
                break;
        }
    }
    int n;
    while(cin >> n && n != 0)
    {
        if(isprime[n])
            cout << n << " is normal.\n";
        else
        {
            bool car = true;
            for(int i = 2 ; i <= n - 1 ; i++)
            {
                if(biEx(i, n, n) % n != i)
                    car = false;
            }
            if(car)
                cout << "The number " << n << " is a Carmichale number.\n";
            else
                cout << n << " is normal.\n";
        }
    }

    return 0;
}