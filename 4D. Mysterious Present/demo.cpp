#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

typedef long long ll;

struct Node {
    int w, h, id;
    bool operator<(const Node &b) const {
        if (w == b.w) return h < b.h;
        return w < b.w;
    }
};

int main() {
    int n, w, h;
    scanf("%d%d%d", &n, &w, &h);
    
    vector<Node> a;
    
    for (int i = 1; i <= n; i++) {
        int ww, hh;
        scanf("%d%d", &ww, &hh);
        if (ww > w && hh > h) {
            a.push_back({ww, hh, i});
        }
    }
    
    if (a.empty()) {
        printf("0\n");
        return 0;
    }

    sort(a.begin(), a.end());

    vector<int> dp(a.size(), 1); // Length of LIS ending at each index
    vector<int> prev(a.size(), -1); // To store the predecessor index for LIS reconstruction

    // Finding the LIS using dynamic programming
    int maxLen = 1, maxIndex = 0;
    for (int i = 1; i < a.size(); i++) {
        for (int j = 0; j < i; j++) {
            if (a[j].w < a[i].w && a[j].h < a[i].h && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                prev[i] = j;
            }
        }
        if (dp[i] > maxLen) {
            maxLen = dp[i];
            maxIndex = i;
        }
    }

    // Output the result
    printf("%d\n", maxLen);
    vector<int> result;
    while (maxIndex != -1) {
        result.push_back(a[maxIndex].id);
        maxIndex = prev[maxIndex];
    }
    
    reverse(result.begin(), result.end());
    for (int i = 0; i < result.size(); i++) {
        printf("%d%c", result[i], i == result.size() - 1 ? '\n' : ' ');
    }

    return 0;
}
