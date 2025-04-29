#include<bits/stdc++.h>
using namespace std;
int main() {
    long long n, k;
    cin >> n >> k;

    // 如果已经有一个水管，直接返回0，不需要任何分水器
    if (n == 1) {
        cout << 0 << endl;
        return 0;
    }

    // 如果 n 小于等于 k，那么只需要一个分水器
    if (n <= k) {
        cout << 1 << endl;
        return 0;
    }

    long long l = 2, r = k, ans = -1;
    long long out = k * (k + 1) / 2; // 计算 k 输出的分水器的最大输出
    out -= k;  // 减去 k

    while (l <= r) {
        long long mid = l + (r - l) / 2;
        long long temp = out - ((mid * (mid - 1)) / 2-mid);// 计算 k到mid 输出的分水器的最大输出
        if (temp >= n) {
            ans = k - (mid - 1);
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    cout << ans << endl;
    return 0;
}