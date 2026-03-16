#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    while(cin >> s && s != "0")
    {
        int diff, odd = 0, even = 0;
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(i % 2 == 0)
                even += s[i] - '0';
            else
                odd += s[i] - '0';
        }
        diff = abs(even - odd);
        if(diff == 0 || diff == 11)
            cout << s << " is a multiple of 11.\n";
        else
            cout << s << " is not a multiple of 11.\n";
    }
       
    return 0;
}