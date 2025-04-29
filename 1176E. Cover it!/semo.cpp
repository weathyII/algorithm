// #include <bits/stdc++.h>
// #include <stdio.h>
// using namespace std;
// void bfs(vector<vector<long long>> &edge, long long node, vector<long long> &dis)
// {
//     dis=vector<long long>(edge.size(), INT_MAX);
//     dis[node] = 0;
//     queue<long long> q;
//     q.push(node);
//     while (!q.empty())
//     {
//         long long u = q.front();
//         q.pop();
//         for (long long v = 1; v < edge.size(); v++)
//         {
//             if (edge[u][v]==1&&dis[v]==INT_MAX)
//             {
//                 dis[v] =dis[u] + 1;
//                 q.push(v);
//             }
//         }
//     }
// }
// int main()
// {
//     long long t, n, m;
//     cin >> t;
//     while (t--)
//     {
//         cin >> n >> m;
//         vector<long long> ans;
//         vector<long long> dis(n + 1, 0);
//         vector<vector<long long>> edge(n + 1, vector<long long>(n + 1, 0));
//         for (long long i = 1; i <= m; i++)
//         {
//             long long a, b;
//             cin >> a >> b;
//             edge[a][b] = 1;
//             edge[b][a] = 1;
//         }
//         bfs(edge, 1, dis);
//         vector<int> even, odd;
// 		for (int i = 1; i <= n; ++i) {
// 			if (dis[i] & 1) odd.push_back(i);
// 			else even.push_back(i);
// 		}
	
// 		if (even.size() < odd.size()) {
// 			cout << even.size() << endl;
// 			for (auto v : even) cout << v  << " ";
// 		} else {
// 			cout << odd.size() << endl;
// 			for (auto v : odd) cout << v  << " ";
// 		}
// 		cout << endl;
//     }
//     return 0;
// }
#include <bits/stdc++.h>

using namespace std;

const int INF = 1e9;

int n, m;
vector<int> d;
vector<vector<int>> g;

void bfs(int s) {
	d = vector<int>(n, INF);
	d[s] = 0;
	
	queue<int> q;
	q.push(s);
	
	while (!q.empty()) {
		int v = q.front();
		q.pop();
		
		for (auto to : g[v]) {
			if (d[to] == INF) {
				d[to] = d[v] + 1;
				q.push(to);
			}
		}
	}
}

int main() {

	
	int t;
	cin >> t;
	
	for (int tc = 0; tc < t; ++tc){
		cin >> n >> m;
		g = vector<vector<int>>(n);
		for (int i = 0; i < m; ++i) {
			int x, y;
			cin >> x >> y;
			--x, --y;
			g[x].push_back(y);
			g[y].push_back(x);
		}
	
		bfs(0);
		vector<int> even, odd;
		for (int i = 0; i < n; ++i) {
			if (d[i] & 1) odd.push_back(i);
			else even.push_back(i);
		}
	
		if (even.size() < odd.size()) {
			cout << even.size() << endl;
			for (auto v : even) cout << v + 1 << " ";
		} else {
			cout << odd.size() << endl;
			for (auto v : odd) cout << v + 1 << " ";
		}
		cout << endl;
	}
	
	return 0;
}