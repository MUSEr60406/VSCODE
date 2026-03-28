#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
ll pow(int n, int p)
{
    int temp = 1;
    while(p--)
        temp *= n;
    return temp;
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
            isprime[i * j] = true;
            if(i % j == 0)
                break;
        }
    }
    int n;
    while(cin >> n && n != 0)
    {
        if(isprime[n])
        {
            cout << n << " is normal.\n";
            continue;
        }
        for(int i = 2 ; i <= n - 1 ; i++)
        {
            if(pow(i, n) % n == i && !isprime[n])
                cout << "The number " << n << "is a Carmichael number.\n";
            else
                cout << n << " is normal.\n";
        }
    }
    return 0;
}