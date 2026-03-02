#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
int main()
{
    int n, c;
    while (cin >> n >> c)
    {
        vector<bool> prime(n + 1, true);
        vector<int> p;
        prime[0] = false;
        prime[1] = true;
        for(int i = 2; i * i <= n; i++) 
            if(prime[i])
                for(int j = i * i; j <= n; j += i)
                    prime[j] = false;

        for(int i = 1 ; i <= n ; i++)
            if(prime[i])
                p.push_back(i);

        int k = p.size();

        int need = (k % 2 == 0 ? 2 * c : 2 * c - 1);
        if (need > k) need = k;

        int mid = k / 2;

        int start = mid - need / 2;
        int end = start + need;
        cout << n << " " << c << ":";
        for (int i = start; i < end; i++)
            cout << " " << p[i];
        cout << "\n\n";
    }
}
