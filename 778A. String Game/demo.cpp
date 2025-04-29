#include <bits/stdc++.h>
using namespace std;
string t, p;
const int N = 2e5 + 5;
int n, m;
int vis[N], num[N];

bool judge(int mid)
{
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < mid; i++)
    {
        vis[num[i] - 1] = 1;
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (vis[i] == 0 && p[ans] == t[i])
        {
            ans++;
        }
        if (ans >= m)
        {
            return true;
        }
    }
    return false;
}
int main()
{
    int ans = 0;
    cin >> t >> p;
    n = t.size();
    m = p.size();
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    int l = 0, r = n - 1;
    int mid;
    while (l <= r)
    {
        /* code */
        mid = (l + r) >> 1;
        if (judge(mid))
        {
            l = mid + 1;
            ans = mid;
        }
        else
        {
            r = mid - 1;
        }
    }
    cout << ans << endl;
}