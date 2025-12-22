//Repetitions
#include<iostream>
#include<string>
#define ll long long
using namespace std;
int main()
{
    ll max = -1, now = 1;
    bool ALLsame = true;
    string s;
    cin >> s;
    for(ll i = 0 ; i < s.size() - 1 ; i++)
    {
        if(s[i] == s[i+1])
            now++;
        else
        {
            if(now > max)
                max = now;
            ALLsame = false;
            now = 1;
        }
    }
    if(now > max)
        max = now;
    cout << (ALLsame ? s.size() : max);
    return 0;
}