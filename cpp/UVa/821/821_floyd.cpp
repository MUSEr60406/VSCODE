#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
using namespace std;
int main()
{
    int Case = 1, a, b;
    while(true)
    {
        vector<vector<int>> len(101, vector<int> (101, 1e9));
        vector<int> node;
        vector<bool> exit(101, false);
        double sum = 0;
        for(int i = 1 ; i <= 100 ; i++)
            len[i][i] = 0;
        while(cin >> a >> b && a != 0 && b != 0)
        {
            len[a][b] = 1;
            if(!exit[a]) 
                node.push_back(a);
            if(!exit[b])
                node.push_back(b);
            exit[a] = exit[b] = true;
        }
        if(node.empty())
            break;
        sort(node.begin(), node.end());
        int n = node.back();
        for(int k = 1 ; k <= n ; k++)
            for(int i = 1 ; i <= n ; i++)
                for(int j = 1 ; j <= n ; j++)
                    if(exit[i] && exit[j] && exit[k]) len[i][j] = min(len[i][j], len[i][k] + len[k][j]);

        for(int i = 1 ; i <= n ; i++)
        {
            for(int j = 1 ; j <= n ; j++)
            {
                if(exit[i] && exit[j] && i != j)
                    sum += len[i][j];
            }
        }
        cout << "Case " << Case << ": average length between pages = ";
        cout << fixed << setprecision(3) << sum / (node.size() * (node.size() - 1)) << " clicks\n";
        Case++;
    }
    return 0;
}