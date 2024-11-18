好的，我们来详细分析这段代码的逻辑和实现，包括动态规划的核心思路、递归状态的定义以及整个代码如何工作。

### 代码结构和逻辑概述

这段代码解决的问题是：给定一定数量的步兵和骑兵，要求排列它们，使得连续的步兵和骑兵数量不超过特定的上限值。代码通过递归和动态规划的方式，计算满足条件的排列数。

### 定义和初始化

#### 宏定义和全局变量
```cpp
#include<bits/stdc++.h>
using namespace std;

#define MOD 100000000
```
`MOD` 的作用是对结果取模，防止溢出，因为排列的方式数可能很大。

#### 变量和数组
```cpp
int succFootman, succHorseman;
int dp[101][101][11][11];
```
- `succFootman` 和 `succHorseman`：分别表示允许连续排列的步兵和骑兵的最大数量。例如，如果 `succFootman = 2`，那么在排列中步兵最多可以连续出现两次，超过这个数量就不允许了。
- `dp` 是一个四维数组，用于存储递归中间状态的结果。数组的维度分别代表：
  - `footman`：当前剩余的步兵数量。
  - `horseman`：当前剩余的骑兵数量。
  - `i1`：当前排列中连续的步兵数量。
  - `i2`：当前排列中连续的骑兵数量。

通过 `dp` 数组存储每种状态的计算结果，以避免重复计算，这是动态规划的核心思想，即 **记忆化递归**。

### `call` 函数：递归的核心

```cpp
int call(int footman, int horseman, int i1, int i2) {
    if (dp[footman][horseman][i1][i2] != -1)
        return dp[footman][horseman][i1][i2];

    if (footman + horseman == 0)
        return 1;
    
    int opt1 = 0, opt2 = 0;

    if (i1 < succFootman && footman > 0)
        opt1 = call(footman - 1, horseman, i1 + 1, 0) % MOD;

    if (i2 < succHorseman && horseman > 0)
        opt2 = call(footman, horseman - 1, 0, i2 + 1) % MOD;

    return dp[footman][horseman][i1][i2] = (opt1 + opt2) % MOD;
}
```

在这段代码中，递归函数 `call` 通过动态规划的思想解决问题。我们可以用状态转移方程来表示递归的转移过程。这有助于理解代码在每一步是如何基于之前的计算结果进行累积的。

### 定义状态

令 `dp[footman][horseman][i1][i2]` 表示在剩余 `footman` 个步兵、`horseman` 个骑兵的情况下，以 `i1` 个连续步兵和 `i2` 个连续骑兵结尾的排列方式数。

### 状态方程

对于每一个状态 `(footman, horseman, i1, i2)`，递归的状态转移方程为：

\[
dp[footman][horseman][i1][i2] = (opt1 + opt2) \mod \text{MOD}
\]

其中：
- \( opt1 \) 表示在当前状态下添加一个步兵的所有可能方式。
- \( opt2 \) 表示在当前状态下添加一个骑兵的所有可能方式。

具体定义如下：

1. **选择添加步兵**：
   - 条件：如果当前连续步兵数量 `i1` 小于允许的最大值 `succFootman`，并且还有剩余步兵 (`footman > 0`)。
   - 则递归调用：`call(footman - 1, horseman, i1 + 1, 0)`。
   - 表示为：
     \[
     opt1 = dp[footman - 1][horseman][i1 + 1][0]
     \]

2. **选择添加骑兵**：
   - 条件：如果当前连续骑兵数量 `i2` 小于允许的最大值 `succHorseman`，并且还有剩余骑兵 (`horseman > 0`)。
   - 则递归调用：`call(footman, horseman - 1, 0, i2 + 1)`。
   - 表示为：
     \[
     opt2 = dp[footman][horseman - 1][0][i2 + 1]
     \]

将两种选择的结果相加并取模：

\[
dp[footman][horseman][i1][i2] = (opt1 + opt2) \mod \text{MOD}
\]

### 边界条件

- 如果 `footman + horseman == 0`，即没有剩余步兵和骑兵时，说明找到了一种有效的排列方式，因此返回 1：

  \[
  dp[0][0][i1][i2] = 1
  \]

- 如果状态已经被计算过（即 `dp[footman][horseman][i1][i2] != -1`），直接返回该状态存储的值。

### 总结

这段代码中的状态转移方程基于选择“是否添加步兵或骑兵”来构建。通过定义不同的状态变量和记录已计算的结果，递归函数得以高效计算所有满足条件的排列数量。

### 主函数：程序的入口

```cpp
int main() {
    int footman, horseman;

    memset(dp, -1, sizeof dp);

    cin >> footman >> horseman >> succFootman >> succHorseman;

    cout << call(footman, horseman, 0, 0) << endl;
}
```

主函数的功能包括：

1. **初始化**：使用 `memset` 将 `dp` 数组初始化为 -1，以便区分未计算的状态。
2. **输入**：从标准输入读取步兵、骑兵数量，以及连续步兵和骑兵的最大数量。
3. **调用递归**：通过 `call(footman, horseman, 0, 0)` 开始递归，计算满足条件的排列数。
4. **输出结果**：将最终结果输出。

### 状态空间分析

`dp` 数组是四维的，维度大小为 `[footman][horseman][succFootman][succHorseman]`。这种记忆化方法将递归的时间复杂度从指数级降到了多项式级，因为每种状态最多只被计算一次。具体来说，状态数量与 `footman` 和 `horseman` 成正比。

### 总结

这段代码通过递归和动态规划解决了一个带约束的排列组合问题。主要利用了 **记忆化搜索**，即每次计算时，先检查是否已计算过，从而避免了重复计算。这种方法特别适合处理具有子结构性质的问题，使得计算更加高效。