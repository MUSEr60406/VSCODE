#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int check(vector<string> &s, char c, int now_s, int now_c)
{
    int now_inv = 0;
    for(int i = now_c + 1 ; i < s[now_s].size() ; i++)
    {
        if(s[now_s][i] == c || s[now_s][i] > c) 
            continue;
        else 
            now_inv++;
    }
    return now_inv;
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int t;
    cin >> t;
    while(t--)
    {
        if(t) cout << "\n";
        int n, m;
        cin >> n >> m;
        vector<string> s(m);
        vector<pair<int,int>> invision_number(m);
        for(int i = 0 ; i < m ; i++)
        {
            int inv = 0;
            cin >> s[i];
            for(int j = 0 ; j < n ; j++)
            {   
                if(s[i][j] == 'A') continue;   
                else inv += check(s,s[i][j], i, j);
            }
            invision_number[i] = {inv, i};
        }
        sort(invision_number.begin(), invision_number.end(), [](pair<int,int> a, pair<int,int> b)
        {
            if(a.first == b.first) return a.second < b.second;
            else return a.first < b.first;
        });
        for(int i = 0 ; i < m ; i++)
        {
            cout << s[invision_number[i].second];
            if(i != m-1) cout << "\n";
        }
    }
    return 0;
}