#include "bits/stdc++.h"

using namespace std;

int n, m, k, id;
int classify[1000005];
int result[1005][1005];
int vis[1005][1005];
char val[1005][1005];

int dfs(int x, int y)
{
	vis[x][y] = id;//标记一个连通块内的点
	if (val[x + 1][y] == '*')
	{
		result[x][y]++;
	}
	if (val[x - 1][y] == '*')
	{
		result[x][y]++;
	}
	if (val[x][y + 1] == '*')
	{
		result[x][y]++;
	}
	if (val[x][y - 1] == '*')
	{
		result[x][y]++;
	}
	if (vis[x - 1][y] == 0 && val[x - 1][y] == '.')
	{
		result[x][y] = dfs(x - 1, y) + result[x][y];
	}
	if (vis[x + 1][y] == 0 && val[x + 1][y] == '.')
	{
		result[x][y] = dfs(x + 1, y) + result[x][y];
	}
	if (vis[x][y - 1] == 0 && val[x][y - 1] == '.')
	{
		result[x][y] = dfs(x, y - 1) + result[x][y];
	}
	if (vis[x][y + 1] == 0 && val[x][y + 1] == '.')
	{
		result[x][y] = dfs(x, y + 1) + result[x][y];
	}
	return result[x][y];
}

int main()
{
	//freopen("i.txt", "r", stdin);
	//freopen("o.txt", "w", stdout);

	int i, j;
	int temp1, temp2;
	scanf("%d%d%d", &n, &m, &k);

	for (i = 1; i <= n; i++)
    {
        scanf("%s", val[i] + 1);
    }

	
	id = 1;
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (val[i][j] == '.'&&vis[i][j] == 0)
			{
				classify[id]= dfs(i, j);
				id++;
			}
		}
	}
	for (i = 1; i <= k; i++)
	{
		scanf("%d%d", &temp1, &temp2);
		printf("%d\n", classify[vis[temp1][temp2]]);
	}
	//system("pause");
	return 0;
}