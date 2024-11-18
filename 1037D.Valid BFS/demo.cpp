#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>
using namespace std;

bool isValidBFS(int n, vector<pair<int, int>>& edges, vector<int>& sequence) {
    // 构建树的邻接表
    vector<vector<int>> graph(n + 1);
    for (auto& edge : edges) {
        int x = edge.first, y = edge.second;
        graph[x].push_back(y);
        graph[y].push_back(x);
    }

    // 检查序列的第一个节点是否是 1
    if (sequence[0] != 1) return false;

    // BFS 初始化
    queue<int> q;
    vector<bool> visited(n + 1, false);
    q.push(1);
    visited[1] = true;

    int index = 1;  // 从序列的第二个元素开始检查

    while (!q.empty()) {
        int node = q.front();
        q.pop();

        // 获取所有未访问的邻居
        vector<int> neighbors;
        for (int neighbor : graph[node]) {
            if (!visited[neighbor]) {
                neighbors.push_back(neighbor);
            }
        }

        // 验证序列中的邻居是否匹配
        unordered_set<int> neighborSet(neighbors.begin(), neighbors.end());
        for (int i = 0; i < neighbors.size(); i++) {
            if (index >= n || neighborSet.find(sequence[index]) == neighborSet.end()) {
                return false;
            }
            visited[sequence[index]] = true;
            q.push(sequence[index]);
            index++;
        }
    }

    return index == n;
}

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> edges(n - 1);
    for (int i = 0; i < n - 1; i++) {
        int x, y;
        cin >> x >> y;
        edges[i] = {x, y};
    }

    vector<int> sequence(n);
    for (int i = 0; i < n; i++) {
        cin >> sequence[i];
    }

    if (isValidBFS(n, edges, sequence)) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }

    return 0;
}
