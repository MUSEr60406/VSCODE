#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
vector<vector<int>> fri;
vector<pii> day_boom;
int main()
{
    //input
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
    for(int i = 0 ; i < T ; i++)


    return 0;
}