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
        int s[500], r;
        cin >> r;
        for(int i = 0 ; i < r ; i++)
            cin >> s[i];

        for(int i = 0 ; i < r - 1 ; i++)
        {
            for(int j = i + 1 ; j < r ; j++)
            {
                if(s[j] < s[i])
                    swap(s[i], s[j]);
            }
        }
        
    }

    return 0;
}