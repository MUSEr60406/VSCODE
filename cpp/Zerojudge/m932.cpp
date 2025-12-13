#include<iostream>
#include<string>
#include<vector>
#include <unordered_set>
using namespace std;
int main(){
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    vector<string> MAP(20);
    unordered_set <char> s;
    int m, n, k, x, y, newx, newy;
    cin >> m >> n >> k;
    x = m - 1, y = 0;
    for(int i = 0 ; i < m ; i++)
    cin >> MAP[i];

    for(int i = 0 ; i < k ; i++)
    {
        int dir;
        char c;
        cin >> dir;
        switch(dir)
        {
            case 0: 
                newx = x - 1;
                newy = y;
            break;
            case 1: 
                newy = y + 1;
                newx = x;
            break;
            case 2: 
                newx = x + 1;
                newy = y + 1;
            break;
            case 3: 
                newx = x + 1;
                newy = y;
            break;
            case 4: 
                newx = x;
                newy = y - 1;
                break;
            case 5: 
                newx = x - 1;
                newy = y - 1;
            break;
        }
        if(newx >= m || newx < 0 || newy >= n || newy < 0) 
            cout << MAP[x][y];
        else 
        {
            cout << MAP[newx][newy];
            x = newx, y = newy;
        }
        c = MAP[x][y];
        s.insert(c);
    }
    cout << "\n" << s.size();


    return 0;
}
