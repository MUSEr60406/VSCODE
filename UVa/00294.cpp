#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<bool> isprime(31700, true);
    vector<int> prime;
    for(int i = 2 ; i <= 31700 ; i++)
    {
        if(isprime[i] == true)
            prime.push_back(i);
    }

    return 0;
}