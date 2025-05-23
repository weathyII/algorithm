### 问题描述

Vivek 有一个迷宫，表示为一个 `n × m` 的网格，其中每个单元格可能是以下几种类型：
- 空地 — `'.'`
- 墙 — `'#'`
- 好人 — `'G'`
- 坏人 — `'B'`

迷宫的出口在 `(n, m)` 位置。Vivek 想通过把一些空地替换成墙来保证：
1. 所有好人能够逃到出口。
2. 所有坏人不能到达任何好人或出口。

需要判断是否存在一种方式来阻挡坏人而不妨碍好人逃脱。

### 解题思路

1. **在坏人周围设墙**：
   - 对每个坏人 `'B'`，将其四周相邻的空地 `'.'` 设为墙 `'#'`，防止坏人向周围移动。
   - 如果坏人的相邻位置有好人 `'G'`，就直接输出 `"No"`，因为无法满足条件。

2. **使用广度优先搜索（BFS）检查可达性**：
   - 放置完墙后，从出口 `(n, m)` 开始，使用 BFS 搜索可达的区域，并统计可以到达的好人数量。
   - 每访问一个单元格，将其标记为已访问（即设为墙 `'#'`），以避免重复访问。

3. **最终判断**：
   - 统计迷宫中初始的好人总数。
   - 如果 BFS 访问到的好人数量等于初始的好人总数，则输出 `"Yes"`，表示所有好人可以到达出口。
   - 否则输出 `"No"`。

### 代码实现

以下是实现上述思路的代码：

```cpp
#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> P;

char mp[55][55];           // 定义地图的二维字符数组，最大尺寸为 55x55
int n, m;                   // 地图的行数和列数
int dx[4] = {0, 1, 0, -1};  // 表示四个方向的 x 偏移量（右、下、左、上）
int dy[4] = {1, 0, -1, 0};  // 表示四个方向的 y 偏移量

// 判断坐标 (x, y) 是否在地图的范围内
bool prim(int x, int y)
{
    return x > 0 && y > 0 && x <= n && y <= m;
}

// 解决单个地图的可行性问题
void solve()
{
    int cnt = 0, cnt2 = 0;  // cnt 表示好人总数，cnt2 表示可达的好人数量
    
    // 输入地图的行数和列数
    cin >> n >> m;
    for(int i = 1; i <= n; i++)           // 输入地图
        for(int j = 1; j <= m; j++)
            cin >> mp[i][j];
    
    // 遍历地图中的每一个格子，处理坏人的周围
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(mp[i][j] == 'B') // 如果找到一个坏人
            {
                for(int k = 0; k < 4; k++)  // 尝试在坏人四周设置墙
                {
                    int px = dx[k] + i, py = dy[k] + j;
                    if(prim(px, py))
                    {
                        if(mp[px][py] == '.')
                            mp[px][py] = '#';    // 将坏人四周的空地设置成墙
                        else if(mp[px][py] == 'G') // 如果坏人周围有好人
                        {
                            cout << "No\n";      // 输出"No"，表示地图不满足要求
                            return;
                        }
                    }
                }
            }
            else if(mp[i][j] == 'G') // 如果是好人，记录好人数量
                cnt++;
        }
    }
    
    // 如果右下角 (n, m) 被设置成了墙，检查地图中是否有好人
    if(mp[n][m] == '#')
    {
        if(cnt == 0) // 如果地图中没有好人，方案是可行的
            cout << "Yes\n";
        else         // 如果地图中还有好人，方案不可行
            cout << "No\n";
        return;
    }
    
    // 使用广度优先搜索 (BFS) 从右下角 (n, m) 开始搜索，统计可达的好人数量
    queue<P> q;
    q.push(P(n, m)); // 从 (n, m) 开始搜索
    mp[n][m] = '#';  // 将起点标记为墙，防止重复访问
    while(!q.empty())
    {
        P pd = q.front();
        q.pop();
        for(int i = 0; i < 4; i++)
        {
            int px = dx[i] + pd.first, py = dy[i] + pd.second;
            if(prim(px, py) && mp[px][py] != '#')
            {
                if(mp[px][py] == 'G') // 如果搜索到好人，计数
                    cnt2++;
                q.push(P(px, py));    // 将下一个坐标加入队列
                mp[px][py] = '#';     // 标记已访问
            }
        }
    }
    
    // 如果可达的好人数量和总的好人数量相同，则方案可行
    if(cnt == cnt2)
        cout << "Yes\n";
    else
        cout << "No\n";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int T; cin >> T;  // 输入测试用例数量
    while(T--)        // 逐个解决每个测试用例
        solve();
    return 0;
}

```

### 代码说明

1. **围堵坏人**：
   - 遍历迷宫，将每个坏人 `'B'` 周围的空地 `'.'` 设为墙 `'#'`。
   - 如果坏人相邻有好人，直接输出 `"No"`，因为此时无法满足条件。

2. **广度优先搜索 (BFS)**：
   - 从出口位置 `(n, m)` 开始 BFS。
   - 每访问一个单元格，标记为已访问（设为墙），记录可以到达的好人数量。

3. **结果判断**：
   - 如果 BFS 到达的好人数量等于好人总数，输出 `"Yes"`；否则输出 `"No"`。

### 时间复杂度分析

- **时间复杂度**：每个测试用例的复杂度为 \(O(n \times m)\)，因为我们需要遍历和搜索整个网格。
- **空间复杂度**：存储迷宫和 BFS 队列的空间复杂度为 \(O(n \times m)\)。

这个解法确保我们只需要在坏人周围设置必要的墙，并高效地判断好人是否可以从出口到达。