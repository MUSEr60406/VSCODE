#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    //建質數表
    vector<bool> isprime(501, true);
    vector<int> prime;
    for(int i = 2 ; i <= 500 ; i++)
    {
        if(isprime[i] == true)
            prime.push_back(i);
        for(int &j : prime)
        {
            if(i * j > 500)
                break;
            isprime[i * j] = false;
            if(i % j == 0)
                break;
        }
    }
    reverse(prime.begin(), prime.end());
    string s;
    while(getline(cin, s))
    {
        if(s == "0")
            break;
        stringstream ss(s);
        ll num, pow, sum = 1;
        while(ss >> num >> pow)
        {
            ll temp = 1;
            for(int i = 0 ; i < pow ; i++)
                temp *= num;
            sum *= temp;
        }
        sum--;
        if(sum == 0)
            cout << 0 << "\n";
        else if(sum == 1)
            cout << "1 1\n";
        else
        {
            for(int d : prime)
            {
                if(sum % d == 0)
                {
                    int count = 0;
                    while(sum % d == 0)
                    {
                        count++;
                        sum /= d;
                    }
                    cout << d << " " << count << " ";
                }
            }
        }
        cout << "\n";
    }
    return 0;
}