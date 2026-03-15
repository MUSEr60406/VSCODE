#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
#define pb push_back
using namespace std;

int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int n;
    vector<int> v(1000);
    while(cin >> n)
    {
        int cnt = 0;
        for(int i = 0 ; i < n ; i++)
            cin >> v[i];
        for(int i = 0 ; i < n ; i++)
        {
            for(int j = i ; j < n ; j++)
            {
                if(v[j] < v[i])
                {
                    swap(v[i], v[j]);
                    cnt++;
                }
            }
        }
        cout << "Minimum exchange operations : " << cnt << "\n";
    }

    return 0;
}