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
    vector<int> v;
    while(cin >> n)
    {
        int cnt = 0;
        v.resize(n);
        for(int i = 0 ; i < n ; i++)
            cin >> v[i];
        for(int i = 0 ; i < n - 1 ; i++)
        {
            for(int j = i ; j < n - i - 1 ; j++)
            {
                if(v[j] > v[j + 1])
                {
                    swap(v[j + 1], v[j]);
                    cnt++;
                }
            }
        }
        cout << "Minimum exchange operations : " << cnt << "\n";
    }

    return 0;
}