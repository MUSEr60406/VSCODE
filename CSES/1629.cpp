//Movie Festival
#include<iostream>
#include<vector>
#include<algorithm>
#define ll long long 
using namespace std;
bool cmp(pair<int,int> A, pair<int,int> B)
{
    return A.second < B.second;
}
int main()
{
    ll n, ans = 0, last_end = 0;
    cin >> n;
    vector<pair<int,int>> movie(n);
    for(int i = 0 ; i < n ; i++)
        cin >> movie[i].first >> movie[i].second;

    sort(movie.begin(), movie.end(), cmp);

    for(auto i : movie)
    {
        if(i.first >= last_end)
        {
            ans++;
            last_end = i.second;
        }
    }
    cout << ans << "\n";
    return 0;
}