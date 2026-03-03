#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //建質數表
    vector<bool> isprime(191, true);
    vector<int> prime;
    for(int i = 2 ; i <= 190 ; i++)
    {
        if(isprime[i] == true)
            prime.push_back(i);
        for(int &j : prime)
        {
            if(i * j > 190)
                break;
            isprime[i * j] = false;
            if(i % j == 0)
                break;
        }
    }
    string s;
    while(getline(cin, s))
    {
        if(s == "0")
            break;
        stringstream ss(s);
        ll num, pow, sum = 1;
        while(ss >> num >> pow)
        {
            cout << num << " " << pow << "\n"; 
            ll temp = 1;
            for(int i = 0 ; i < pow ; i++)
                temp *= num;
            sum += temp;
        }
        cout << sum;
    }
    return 0;
}