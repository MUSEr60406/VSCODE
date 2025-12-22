//Weird Algorithm
#include<iostream>
using namespace std;
void f(long long int n)
{
    cout << n << " ";
    if(n == 1)
        return;
    if(n % 2 == 0)
        f(n/2);
    else
        f(3*n+1);
}
int main()
{
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);
    long long int n;
    cin >> n;
    f(n);
    return 0;
}