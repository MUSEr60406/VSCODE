#include<iostream>
using namespace std;
int main()
{
    const int mod = 10000007;
    long long t = 0, p = 0;
    string text, pattern;
    int ans = 0;
    cin >> text >> pattern;

    int len_t = text.size(), len_p = pattern.size();
    
    long long power = 1;
    for(int i = 1 ; i < len_p ; i++)
        power = (power * 26) % mod;
    for(int i = 0 ; i < len_p ; i++)
    {
        p = (p * 26 + (pattern[i] - 'a')) % mod;
        t = (t * 26 + (text[i] - 'a')) % mod;
    }
    for(int i = 0 ; i <= len_t - len_p ; i++)
    {
        if(p == t)
            ans++;
        if(i < len_t - len_p)
        {
            t = (t - (text[i] - 'a') * power % mod + mod) % mod;
            t = (t * 26 + (text[i + len_p] - 'a')) % mod;
        }
    }
    cout << ans;
}
