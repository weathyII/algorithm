// #include <bits/stdc++.h>
// using namespace std;
// int bfs(vector<vector<int>> adj, int n)
// {
//     int k = adj.size(), count = 0;
//     vector<int> visited(k, 0);
//     queue<int> q;
//     visited[n] = 1;
//     q.push(n);
//     while (!q.empty())
//     {
//         int u = q.front();
//         q.pop();
//         for (int v = 1; v < k; v++)
//         {
//             if (visited[v] == 0)
//             {
//                 if (adj[u][v] == 1)
//                 {
//                     visited[v] = 1;
//                     q.push(v);
//                 }
//                 if (adj[u][v] == -1)
//                 {
//                     count++;
//                     visited[v] = 1;
//                     q.push(v);
//                 }
//             }
//         }
//     }
//     if (accumulate(visited.begin()+1, visited.end(), 0) == k-1)
//     {
//         return count;
//     }

//     return INT_MAX;
// }

// int main()
// {
//     int n;
//     cin >> n;
//     vector<vector<int>> adj(n + 1, vector<int>(n + 1, 0));
//     for (int i = 0; i < n-1; i++)
//     {
//         int u, v;
//         cin >> u >> v;
//         adj[u][v] = 1;
//         adj[v][u] = -1;
//     }

//     vector<int> res(n + 1, 0);
//     int minnum = INT_MAX;
//     for (int i = 1; i <= n; i++)
//     {
//         res[i] = bfs(adj, i);
//         minnum = min(minnum, res[i]);
//     }
//     vector<int> ans;
//     for (int i = 1; i <= n; i++)
//     {
//         if (res[i] == minnum)
//         {
//             ans.push_back(i);
//         }
//     }
//     sort(ans.begin(), ans.end());
//     cout << minnum << endl;
//     for (auto i : ans)
//     {
//         cout << i << " ";
//     }
//     return 0;
// }

#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>

int main() {
    // Speed up I/O.
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    
    // Build the tree as an adjacency list.
    // Each edge is stored as a pair {neighbor, bool} where the bool indicates
    // the “original” orientation: for an input edge (from, to), we set
    // graph[from] gets a 'true' (red edge) while graph[to] gets a 'false' (green edge).
    std::vector<std::vector<std::pair<int, bool>>> graph(n + 1);
    for (int i = 0; i < n - 1; ++i) {
        int from, to;
        std::cin >> from >> to;
        graph[from].emplace_back(to, true);
        graph[to].emplace_back(from, false);
    }
    
    // dp[i] will hold the number of edge flips needed if vertex i is chosen as the capital.
    std::vector<int> dp(n + 1, 0);

    // First DFS: calculate the number of flips needed when vertex 1 is chosen as capital.
    // For every edge from a vertex u to its child v, we need to flip it
    // if the current orientation is not the one required (i.e. not red).
    std::function<int(int, int)> dfsone = [&](int u, int parent) -> int {
        int amount = 0;
        for (auto [v, isRed] : graph[u]) {
            if (v == parent)
                continue;
            // When traversing down from u to v, we require the edge to be red.
            // If it is not (i.e. if isRed is false), a flip is needed.
            bool flipNeeded = !isRed;
            amount += flipNeeded;
            amount += dfsone(v, u);
        }
        return amount;
    };

    dp[1] = dfsone(1, 0);

    // Second DFS: using the dp value computed for vertex 1,
    // adjust the count for every vertex by considering the effect of "re-rooting" the tree.
    std::function<void(int, int)> dfsall = [&](int u, int parent) {
        for (auto [v, isRed] : graph[u]) {
            if (v == parent)
                continue;
            // If the edge from u to v is red, then when moving the capital from u to v,
            // the required number of flips increases by 1; if it is green, it decreases by 1.
            dp[v] = dp[u] + (isRed ? 1 : -1);
            dfsall(v, u);
        }
    };

    dfsall(1, 0);

    // Find the minimum number of flips over all possible capitals.
    int minFlips = *std::min_element(dp.begin() + 1, dp.end());
    std::cout << minFlips << "\n";
    for (int i = 1; i <= n; ++i)
        if (dp[i] == minFlips)
            std::cout << i << " ";
    std::cout << "\n";
    
    return 0;
}
