#include<iostream>
using namespace std;

int main(){
    int n,m,nm, counts ;
    while(cin >> n)
    {
        int  s[1000000];
        for(int i = 0; i < n; i++ )
        {
            cin >> s[i];
        }
        sort(s, s + n);
        if (n %2 == 0 )
        {
             m = n / 2;
             nm = s[m-1];
        }
        else
        {
            m = (n + 1) / 2;
            nm = s[m-1];
        }
              for (int i = 0; i <= m - 1; i++)
             {
                 if (s[i] == nm) counts++;
             }
             cout << nm << " " << counts;

    }



}