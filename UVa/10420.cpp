#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    cin >> n;
    while(n--)
    {
        cin.ignore();
        string s; 
        while(getline(cin, s))
        {
            string country = ""; 
            map<string,int> country_cnt; 
            for(int i = 0 ; i < s.size() ; i++) //"Spain Donna"
            {
                if(s[i] == ' ')
                    break;
                country += s[i]; 
            }
            country_cnt[country]++; 
        }
    }
    return 0;
}