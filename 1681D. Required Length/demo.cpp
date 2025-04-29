#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    long long x;
    cin >> x;
    queue<long long> q;
    map<long long, int> ans;
    ans[x] = 0;
    q.push(x);
    while (!q.empty())
    {
        long long u = q.front();
        q.pop();
        string s = to_string(u);
        if (s.size() == n)
        {
            cout << ans[u] << endl;
            return 0;
        }
        for (auto c : s)
        {
            if (c == '0')
                continue;
            long long v = u * int(c - '0');
            if (!ans.count(v))
            {
                ans[v] = ans[u] + 1;
                q.push(v);
            }
        }
    }
    cout << -1 << endl;
    return 0;
}