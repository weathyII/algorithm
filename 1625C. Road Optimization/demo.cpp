#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

const int maxN = 505, INF = 0x3f3f3f3f;

int dp[maxN][maxN], n, l, k, b[maxN], d[maxN];

int main()
{
    scanf("%d%d%d", &n, &l, &k);
    for (int i = 0; i < n; ++i)
        scanf("%d", &d[i]);
    for (int i = 0; i < n; ++i)
        scanf("%d", &b[i]);
    memset(dp, 0x3f, sizeof dp);
    dp[0][0] = 0;
    d[n] = l;
    for (int i = 1; i <= n; ++i)
        dp[i][0] = dp[i - 1][0] + b[i - 1] * (d[i] - d[i - 1]);
    for (int i = 0; i < n; ++i)
        for (int j = 0; j <= k; ++j)
            for (int pos = i + 1; pos <= n; ++pos)
                dp[pos][j + pos - i - 1] = min(dp[pos][j + pos - i - 1], dp[i][j] + b[i] * (d[pos] - d[i]));
    int ans = INF;
    for (int i = 0; i <= k; ++i)
        ans = min(ans, dp[n][i]);
    printf("%d\n", ans);
    return 0;
}