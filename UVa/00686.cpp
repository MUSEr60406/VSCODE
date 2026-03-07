#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
  vector<bool> isprime(33001, true);
    vector<int> prime;
    for(int i = 2 ; i <= 33000 ; i++)
    {
        if(isprime[i] == true)
            prime.push_back(i);
        for(int &j : prime)
        {
            if(i * j > 33000)
                break;
            isprime[i * j] = false;
            if(i % j == 0)
                break;
        }
    }
    return 0;
}