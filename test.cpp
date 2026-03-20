#include<iostream>
#include <algorithm>
#include<vector>
using namespace std;

int main(){
    int n, m ,nm ,nm1, a;
    while(cin >> n)
    {
        int counts = 0;
        vector <int> s(n);
        for(int i = 0; i < n; i++)
        {
            cin >> s[i];
        }
        sort(s.begin(),s.end());
        if (n % 2 == 0 )
        {
             m = (n - 1) / 2; 
             nm = s[m];
             nm1 = s[m + 1];
             a = s[m + 1] - s[m] + 1;   
        }
        else
        {
            m = n / 2; // 0 1 2 3 4, n = 5
            nm = s[m];
            a = 1;
        }
        for (int i = 0; i < n; i++)
        {
            if(n % 2 == 0)
            {
                if (s[i] == nm || s[i] == nm1) 
                    counts++;
            }
            else
            {
                if(s[i] == nm)
                    counts++;
            }
        }
        cout << nm << " " << counts << " " << a << "\n";

    }

return 0;

}