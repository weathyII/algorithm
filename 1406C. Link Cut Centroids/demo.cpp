#include <bits/stdc++.h>
using namespace std;

// Function to perform DFS and calculate subtree sizes
int dfs(vector<vector<int>> &edges, vector<int> &sizes, vector<bool> &visited, int node)
{
    visited[node] = true;
    sizes[node] = 1;
    for (auto child : edges[node])
    {
        if (!visited[child])
        {
            sizes[node] += dfs(edges, sizes, visited, child);
        }
    }
    return sizes[node];
}

// Function to find the centroid(s)
vector<int> findCentroids(vector<vector<int>> &edges, vector<int> &sizes, int n)
{
    vector<int> centroids;
    int total_size = sizes[0]; // Size of the whole tree
    for (int i = 0; i < n; i++)
    {
        int max_comp = 0;
        for (auto child : edges[i])
        {
            if (sizes[child] < sizes[i])
            { // Avoid double counting the parent
                max_comp = max(max_comp, sizes[child]);
            }
        }
        max_comp = max(max_comp, total_size - sizes[i]); // Account for the component left out by removing `i`
        if (max_comp <= total_size / 2)
        {
            centroids.push_back(i);
        }
    }
    return centroids;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<vector<int>> edges(n);
        vector<int> sizes(n);
        vector<bool> visited(n, false);

        // Read edges and build the tree
        for (int i = 0; i < n - 1; i++)
        {
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            edges[u].push_back(v);
            edges[v].push_back(u);
        }

        // Compute subtree sizes
        dfs(edges, sizes, visited, 0);

        // Find centroids
        vector<int> centroids = findCentroids(edges, sizes, n);

        // Output result based on centroids
        if (centroids.size() == 1)
        {
            for (auto child : edges[centroids[0]])
            {
                cout << centroids[0] + 1 << " " << child + 1 << endl;
                cout << centroids[0] + 1 << " " << child + 1 << endl;
                break;
            }
        }
        else
        {
            // Find an edge to print
            for (auto child : edges[centroids[0]])
            {
                if (child != centroids[1])
                {
                    cout << centroids[0] + 1 << " " << child + 1 << endl;
                    cout << centroids[1] + 1 << " " << child + 1 << endl;
                    break;
                }
            }
        }
    }
    return 0;
}
