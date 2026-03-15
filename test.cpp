#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
#define pb push_back
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<int> s; //{}
    s.push_back(2);
    s.push_back(1); //{2, 1}
    s.pop_back(); //{2}
    s.assign(10, 2);
    return 0;
}