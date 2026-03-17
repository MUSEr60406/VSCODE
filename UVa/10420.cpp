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
        map<string,int> country_cnt; 
        while(getline(cin, s))
        {
            string country = ""; 
            for(int i = 0 ; i < s.size() ; i++) //"Spain Donna"
            {
                if(s[i] == ' ')
                    break;
                country += s[i]; 
            }
            country_cnt[country]++; 
        }
        for(auto it = country_cnt.begin() ; it != country_cnt.end() ; it++)
            cout << it->first << " " << it->second;
    }
    return 0;
}