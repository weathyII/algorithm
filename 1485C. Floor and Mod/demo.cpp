#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        long long x, y;
        cin >> x >> y;
        long long ans = 0;
        for(long long k=1;k<sqrt(x);k++)
        {
           ans+=max(0ll,min(y,x/k-1)-k);
        }
        cout << ans << endl;
    }
    return 0;
}