#include "bits/stdc++.h"
using namespace std;


#define ll long long
#define pb push_back
#define fi first
#define se second

const int N = 2e5 + 10;
int bit[N];
int a[N];

void solve()
{
    int n;
    cin >> n;
    for(int i = 1; i <= n; ++i) cin >> a[i];
    for(int i = 1; i <= n; ++i){
        for(int b = 0; b <= 25; ++b){
            if(a[i] & (1 << b)) bit[b]++;
        }
    }

    ll ans = 0;
    for(int i = 1; i <= n; ++i){
        int num = 0;
        for(int b = 30; b >= 0; --b){
            if(bit[b]){
                num += (1 << b);
                bit[b]--;
            }
        }
        ans += (ll)num * num;
    }
    //cout << "ans = ";
    cout << ans << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    solve();

    return 0;
}

