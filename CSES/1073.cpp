//Towers
#include<iostream>
#include<vector>
#define ll long long 
using namespace std;
int main()
{
    ios:: sync_with_stdio(0), cin.tie(0);
    ll n;
    cin >> n;
    vector<int> tower;
    for(ll i = 0 ; i < n ; i++)
    {
        ll h;
        cin >> h;
        if(i == 0)
        {
            tower.push_back(h);
            continue;
        }
        ll left = 0, right = tower.size() - 1, build_pos = -1;
        while(left <= right)
        {
            ll mid = left + (right - left)/2;
            if(tower[mid] > h)
            {
                right = mid - 1;
                build_pos = mid;
            }
            else
                left = mid + 1;
        }
        if(build_pos != -1)
            tower[build_pos] = h;
        else
            tower.push_back(h);

    }
    cout << tower.size() << "\n";
}
