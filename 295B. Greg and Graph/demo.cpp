#include <iostream>

using namespace std;

typedef long long LL;

const int N = 510;
int a[N][N], d[N];
LL ans[N];
bool st[N];

void solve()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) cin >> a[i][j];
    for (int i = 1; i <= n; i++) cin >> d[i];
    for (int q = n; q > 0; q--) {
        int k = d[q];
        st[k] = true;
        ans[q] = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                a[i][j] = min(a[i][j], a[i][k] + a[k][j]);
                if (st[i] && st[j]) ans[q] += a[i][j];//表示i，j两个点都已经出现，可以更新
            }
        }
    }
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    return;
}

int main()
{
    cin.tie(0);
    cout.tie(0);
    solve();
    return 0;
}
