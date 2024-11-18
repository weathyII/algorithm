#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, m, k;
    cin >> n >> m >> k;

    vector<long long> p(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
    }

    // Precompute the sum of each subarray of length m
    vector<long long> subarraySum(n + 1, 0);
    long long currentSum = 0;
    for (int i = 1; i <= n; i++) {
        currentSum += p[i];
        if (i >= m) {
            if (i > m) currentSum -= p[i - m];
            subarraySum[i] = currentSum;
        }
    }

    // DP array to store maximum possible sum using j subarrays of length m up to index i
    vector<vector<long long>> dp(n + 1, vector<long long>(k + 1, 0));

    for (int j = 1; j <= k; j++) {
        for (int i = j * m; i <= n; i++) {
            // Either we take the subarray ending at i or we don't
            dp[i][j] = max(dp[i - 1][j], dp[i - m][j - 1] + subarraySum[i]);
        }
    }

    // The result is the maximum sum with exactly k subarrays of length m for the first n elements
    cout << dp[n][k] << endl;

    return 0;
}
