### 解决思路
1. **检测环的存在**：使用拓扑排序（Kahn算法）来检测图中是否存在环。如果存在环，直接返回-1。
2. **动态规划**：对于每个节点，维护一个数组，记录到达该节点时每个字符的最大出现次数。利用拓扑排序的顺序来处理每个节点，并更新其邻接节点的字符出现次数。
3. **计算最大值**：遍历所有节点的字符出现次数，找到最大值。

### 解决代码
```cpp
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
```

### 代码解释
1. **输入处理**：读取节点数、边数和每个节点的字符，构建邻接表和入度数组。
2. **拓扑排序**：使用Kahn算法检测图中是否存在环，并生成拓扑排序序列。如果拓扑序列的长度不等于节点数，说明存在环，直接输出-1。
3. **动态规划初始化**：每个节点的初始字符出现次数设为1（自身字符），其余为0。
4. **处理拓扑序**：按照拓扑顺序处理每个节点，更新其邻接节点的字符出现次数。对于每条边u→v，复制u的字符计数到临时数组，增加v的字符计数，并更新v的计数数组。
5. **计算最大值**：遍历所有节点的字符出现次数，找到最大值并输出。

这种方法通过拓扑排序确保了无环处理，并利用动态规划高效地计算最长路径中的字符最大出现次数，时间复杂度为O(n + m * 26)，适用于较大的输入规模。