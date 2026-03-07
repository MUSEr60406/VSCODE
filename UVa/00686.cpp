#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<bool> isprime(301, true);
    vector<int> prime;
    for(int i = 2 ; i <= 300 ; i++)
    {
        if(isprime[i] == true)
            prime.push_back(i);
        for(int &j : prime)
        {
            if(i * j > 300)
                break;
            isprime[i * j] = false;
            if(i % j == 0)
                break;
        }
    }
    int n;
    for(int i : prime)
        cout << i << "\n";
    vector<bool> visited(prime.back() + 1, false);
    while(cin >> n && n != 0)
    {
        int ans = 0;
        for(int i = 0 ; i < prime.size() - 1 ; i++)
        {
            for(int j = i + 1 ; j < prime.size() ; j++)
            {
                if(!visited[i] && !visited[j] && prime[i] + prime[j] == n)
                {
                    visited[i] = visited[j] = true;
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}