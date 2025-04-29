int bfs(vector<vector<int>> adj, int n)
{
    int k = adj.size(), count = 0;
    vector<int> visited(k, 0);
    queue<int> q;
    visited[n] = 1;
    q.push(n);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v = 1; v < k; v++)
        {
            if (visited[v] == 0)
            {
                if (adj[u][v] == 1)
                {
                    visited[v] = 1;
                    q.push(v);
                }
                if (adj[u][v] == -1)
                {
                    count++;
                    visited[v] = 1;