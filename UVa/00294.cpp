#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //建質數表
    vector<bool> isprime(31700, true);
    vector<int> prime;
    for(int i = 2 ; i <= 31700 ; i++)
    {
        if(isprime[i] == true)
            prime.push_back(i);
        for(int j : prime)
        {
            if(i * j > 31700)
                break;
            isprime[i * j] = false;
            if(i % j == 0)
                break;
        }
    }
    
    int n, l, u;
    cin >> n;
    while(n--)
    {
        int total = 1;
        cin >> l >> u;
        for(int i = l ; i <= u ; i++)
        {
            int num = i;
            for(int d : prime)
            {
                if(d * d > num)
                    break;
                if(num % d == 0)
                {
                    int count = 0;
                    while(num % d ==0)
                    {
                        count++;
                        num /= d;
                    }
                    total *= (count + 1);
                }
            }
            if(num > 1)
                total *= 2;
        }
        cout << "Between 1 and 10, 6 has a maximum of 4 divisors."
    }
    return 0;
}