#include<bits/stdc++.h>
#define pii pair<int,int>
#define pll pair<long,long>
#define ll long long
using namespace std;
set<int> block_locks;
unordered_map<int, unordered_map<int, char>> locks;
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    int c;
    cin >> c;
    while(c--)
    {
        locks.clear();
        block_locks.clear();
        cin.ignore();
        string s;
        while(getline(cin, s) && s != "#")
        {
            if(s.empty())
                continue;
            stringstream ss(s);
            char mode; 
            int trid, item;
            ss >> mode >> trid >> item;
            //
            if(block_locks.count(trid))
            {
                cout << "IGNORED\n";
                continue;
            }
            bool conflict = false;
            if(locks.count(item))
            {
                for(auto &[t, m] : locks[item])
                {
                    if(t != trid)
                    {
                        if(m == 'X' || mode == 'X')
                        {
                            conflict = true;
                            break;
                        }
                    }
                }
            }
            if(conflict)
            {
                cout << "DENIED\n";
                block_locks.insert(trid);
            }
            else
            {
                cout << "GRANTED\n";
                if(!locks[item].count(trid) || mode == 'X')
                    locks[item][trid] = 'X';
            }
            
        }
        if(c)
            cout << "\n";
    }

    return 0;
}