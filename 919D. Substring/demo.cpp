#include<bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<char> chars(n);
    for (int i = 0; i < n; ++i) {
        cin >> chars[i];
    }

    vector<vector<int>> adj(n);
    vector<int> in_degree(n, 0);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        adj[u - 1].push_back(v - 1);
        in_degree[v - 1]++;
    }

    // Kahn's algorithm for topological sort to detect cycles
    queue<int> q;
    vector<int> topo;
    for (int i = 0; i < n; ++i) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()) {
        int u = q.front();
        q.pop();
        topo.push_back(u);
        for (int v : adj[u]) {
            in_degree[v]--;
            if (in_degree[v] == 0) {
                q.push(v);
            }
        }
    }

    // If there's a cycle, output -1
    if (topo.size() != n) {
        cout << -1 << endl;
        return 0;
    }

    // DP array to track max occurrences of each character up to each node
    vector<vector<int>> dp(n, vector<int>(26, 0));
    for (int i = 0; i < n; ++i) {
        int c = chars[i] - 'a';
        dp[i][c] = 1;
    }

    // Process nodes in topological order to update DP values
    for (int u : topo) {
        for (int v : adj[u]) {
            vector<int> temp = dp[u];
            int c = chars[v] - 'a';
            temp[c]++;
            for (int i = 0; i < 26; ++i) {
                dp[v][i] = max(dp[v][i], temp[i]);
            }
        }
    }

    // Find the maximum occurrence across all nodes and characters
    int max_count = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < 26; ++j) {
            max_count = max(max_count, dp[i][j]);
        }
    }

    cout << max_count << endl;

    return 0;
}