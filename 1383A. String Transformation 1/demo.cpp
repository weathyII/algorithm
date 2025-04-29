#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        string a, b;
        cin >> n >> a >> b;
        bool bad = false;
        vector<vector<int>> adj(20);
        for (int i = 0; i < n; i++)
            if (a[i] != b[i])
            {
                if (a[i] > b[i])
                {
                    bad = true;
                    cout << "-1" << endl;
                    break;
                }
                adj[a[i]-'a'].push_back(b[i]-'a');
				adj[b[i]-'a'].push_back(a[i]-'a');
            }
        if (bad)
            continue;

        vector<bool> mark(20);
        function<void(int)> dfs = [&](int u)
        {
            mark[u] = true;
            for (auto v : adj[u])
            {
                if (!mark[v])
                    dfs(v);
            }
        };
        int ans = 20;
        for (int i = 0; i < 20; i++)
        {
            if (!mark[i])
            {
                dfs(i);
                ans--;
            }
        }

        cout << ans << endl;
    }
    return 0;
}