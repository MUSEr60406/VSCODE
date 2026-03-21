#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
string f(string s)
{
    if(s.size() == 1)
        return s;
    int n = 0;
    for(auto &c : s)
        n += c - '0';
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    while(cin >> s && s != "0")
    {
        cout << f(s);
    }

    return 0;
}