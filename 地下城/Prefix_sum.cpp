#include<iostream>
#include<vector>
using namespace std;
int main()
{
    int n, q;
    cin >> n >> q;
    vector<long long> numbers(n + 1);
    vector<long long> prefix_sum(n + 1);
    for(int i = 1 ; i <= n ; i++)
        cin >> numbers[i];
    prefix_sum[0] = numbers[0];
    for(int i = 1 ; i <= n ; i++)
        prefix_sum[i] = prefix_sum[i - 1] + numbers[i];
    while(q--)
    {
        int a, b;
        cin >> a >> b;
        cout << prefix_sum[b] - prefix_sum[a - 1] << "\n";
    }
    return 0;
}