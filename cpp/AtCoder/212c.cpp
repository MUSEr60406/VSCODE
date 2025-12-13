#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<climits>
using namespace std;
int main()
{
    int n, m;
    long long int min_differnce = LLONG_MAX;
    cin >> n >> m;
    vector<long long int> A(n);
    vector<long long int> B(m);
    for(int i = 0 ; i < n ; i++)
        cin >> A[i];
    for(int i = 0 ; i < m ; i++)
        cin >> B[i];
    sort(B.begin(), B.end());
    cout << 777;
    for(int i : A)
    {
        int left = 0, right = m-1, target_idx = m;
        while(left <= right)
        {
           int mid = left + (right - left) / 2;
           if(B[mid] >= i)
           {
                target_idx = mid;
                right = mid - 1;
           }
           else
            left = mid + 1;
        }
        if(target_idx < m)
            min_differnce = min(abs(B[target_idx] - i), min_differnce);
        if(target_idx > 0)
            min_differnce = min(abs(B[target_idx - 1] - i), min_differnce);
    }
    cout << min_differnce << "\n";

    return 0;
}