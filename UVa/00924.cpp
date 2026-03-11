#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
vector<vector<int>> fri;
vector<int> source;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int E, T;
    cin >> E;
    fri.assign(E, {});
    for(int i = 0 ; i < E ; i++)
    {
        int temp;
        cin >> temp;
        fri[i].push_back(temp);
    }
    cin >> T;
    source.assign(T,{});
    for(int &i : source)
        cin >> i;


    return 0;
}