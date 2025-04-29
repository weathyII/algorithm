#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<pair<long long, long long>> a;
        vector<long> k, h;
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            k.push_back(x);
        }
        for (int i = 1; i <= n; i++)
        {
            int x;
            cin >> x;
            h.push_back(x);
        }
        for (int i = 0; i < n; i++)
        {
            a.push_back(make_pair(k[i] - h[i], k[i]));
        }
        sort(a.begin(), a.end(), [&](pair<long long, long long> &a, pair<long long , long long> &b)
             { return a.first < b.first; });
        long long ans = 0;
        long long l = -1, r = -1;
        for (auto it : a)
        {
            if (it.first >= r)
            {
                ans += (r - l + 1) * (r - l) / 2;
                l = it.first;
                r = it.second;
            }
            else
            {
                r = max(r, it.second);
            }
        }
        ans += (r - l + 1) * (r - l) / 2;
        cout << ans << endl;
    }
    return 0;
}