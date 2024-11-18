#include <iostream>
#include <vector>

const int MOD = 1000000007;
const int MAX_N = 100000;

using namespace std;

int main() {
    int t, k;
    cin >> t >> k;

    // dp[i]表示长度为i的有效序列的个数
    vector<long long> dp(MAX_N + 1, 0);
    dp[0] = 1;  // 空序列是有效的

    // 填充dp数组
    for (int i = 1; i <= MAX_N; ++i) {
        dp[i] = dp[i - 1];  // 序列末尾是红色花朵
        if (i >= k) {
            dp[i] = (dp[i] + dp[i - k]) % MOD;  // 序列末尾是k个白色花朵
        }
    }

    // 计算dp数组的前缀和
    vector<long long> prefix_sum(MAX_N + 1, 0);
    for (int i = 1; i <= MAX_N; ++i) {
        prefix_sum[i] = (prefix_sum[i - 1] + dp[i]) % MOD;
    }

    // 处理每个测试用例
    while (t--) {
        int ai, bi;
        cin >> ai >> bi;
        // 结果是prefix_sum[bi] - prefix_sum[ai-1]
        long long result = (prefix_sum[bi] - prefix_sum[ai - 1] + MOD) % MOD;
        cout << result << endl;
    }

    return 0;
}
