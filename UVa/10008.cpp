#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    string s;
    while(getline(cin, s))
    {
        for(int i = 0 ; i < s.size() ; i++)
        {
            if(s[i] == ' ')
                continue;
            cout << s[i] << ": " << (int)s[i] << " "; 
        }
        cout << "\n";
    }

    return 0;
}