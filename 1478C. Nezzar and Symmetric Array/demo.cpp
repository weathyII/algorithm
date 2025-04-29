#include <iostream>
#include <vector>
#include <algorithm>

using ll = long long;
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        // 读入 2*n 个数
        vector<ll> a(2 * n);
        for (ll &x : a) {
            cin >> x;
        }

        // 按降序排序
        sort(a.begin(), a.end(), greater<ll>());

        // 检查相邻的数是否成对相等，同时构造数组 b
        bool possible = true;
        vector<ll> b(n), d(n, 0);
        for (int i = 0; i < n; ++i) {
            if (a[2 * i] != a[2 * i + 1]) {
                possible = false;
                break;
            }
            b[i] = a[2 * i];
        }

        // 如果初步检查通过，计算辅助数组 d
        if (possible) {
            for (int i = 1; i < n; ++i) {
                // 如果相邻 b 值相等或差值不满足整除条件，则构造失败
                if (b[i - 1] == b[i] || (b[i - 1] - b[i]) % (2 * (n - i)) != 0) {
                    possible = false;
                    break;
                }
                d[i] = (b[i - 1] - b[i]) / (2 * (n - i));
            }
        }

        // 利用辅助数组 d 修正 b[n-1]，以还原出 2*n*a_1
        if (possible) {
            for (int i = 1; i < n; ++i) {
                b[n - 1] -= 2 * i * d[i];
            }
            // 检查修正后的 b[n-1] 是否大于零且能被 2*n 整除
            if (b[n - 1] <= 0 || b[n - 1] % (2 * n) != 0) {
                possible = false;
            }
        }

        cout << (possible ? "YES" : "NO") << "\n";
    }

    return 0;
}
