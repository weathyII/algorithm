#include<bits/stdc++.h>
using namespace std;




int main(){
    int t;
    cin>>t;
    while(t--){
        int n, m;
    cin >> n >> m;
    vector<int> a(n);
    for (auto &x : a) cin >> x;
    auto b = a;
    sort(b.begin(), b.end());
    int ans = 0;
    for (int i = 0; i < n && b[i] <= m; ++i) {
      m -= b[i];
      ++ans;
    }
    if (ans != 0 && ans != n && m + b[ans - 1] >= a[ans]) ++ans;
    cout << n + 1 - ans << '\n';
    }
}