#include <bits/stdc++.h>

using namespace std;

int const N = 3e5 + 1;  // 数组的最大长度
int n, a[N];  // 数组 a 和长度 n
vector<int> all, sol;  // all 存储所有可能的子序列，sol 存储最终结果
map<int, int> dp;  // dp 用来记录每个数字结尾的最长连续子序列长度

int main() {
  cin >> n;  // 读取数组的长度
  for(int i = 0; i < n; ++i)
    cin >> a[i];  // 读取数组元素
  
  int mx = 0, val;  // mx 记录最长子序列的长度，val 记录该子序列的最后一个元素
  for(int i = 0; i < n; ++i) {
    dp[a[i]] = dp[a[i] - 1] + 1;  // 更新 dp 数组
    if(dp[a[i]] > mx)  // 如果当前元素的子序列长度大于 mx
      mx = dp[a[i]], val = a[i];  // 更新最长子序列长度和结束元素的值
  }

  cout << mx << endl;  // 输出最长子序列的长度
  // 反向查找最长子序列的元素，构造 sol 数组
  for(int i = n - 1; i >= 0; --i)
    if(a[i] == val) {
      sol.push_back(i + 1);  // 将索引（从 1 开始）加入结果
      --val;  // 更新 val
    }

  reverse(sol.begin(), sol.end());  // 反转结果，使其顺序从前到后
  for(int i = 0; i < sol.size(); ++i)
    cout << sol[i] << ' ';  // 输出结果
  cout << endl;

  return 0;
}
