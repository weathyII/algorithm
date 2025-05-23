你描述的数学推导与代码实现的思路是一致的，以下是对公式的详细解释以及如何得出这个结果：

---

### **问题描述**
我们需要将数组重新排列，使得相同的数字尽可能分散，并在两个相同数字之间插入其他数字。目标是找到最优的分布方法，同时满足上述条件。

---

### **数学推导**

#### **1. 循环节的构造**
- 假设：
  - 出现次数最多的数字有 \( k \) 种，每种出现了 \( \text{cnt} \) 次。
  - 总的数字个数为 \( n \)。
- 我们可以将这些最高频率的数字作为一个“循环节”。每个循环节中有 \( k \) 个元素。
- 在每两个循环节之间，我们需要插入其他的数字进行“填空”。

---

#### **2. 公式推导**

1. **总空隙数**：
   - \( k \) 个出现次数最多的数字分布在 \( \text{cnt} \) 个循环节中，会形成 \( \text{cnt} - 1 \) 个间隙。

2. **每个间隙需要的元素**：
   - 每个间隙平均需要填充 \( \frac{n - \text{cnt} \times k}{k - 1} \) 个元素。
   - 这里 \( n - \text{cnt} \times k \) 是剩余的数字总数，\( k - 1 \) 是每个循环节之间的空隙数。

3. **答案公式**：
   - 俩循环节之间的间隔等于：
     \[
     \left\lfloor \frac{n - \text{cnt} \times k}{k - 1} \right\rfloor + \text{cnt} - 1
     \]
   - 其中：
     - \( \left\lfloor \frac{n - \text{cnt} \times k}{k - 1} \right\rfloor \)：表示填空需要的最小长度。
     - \( \text{cnt} \)：循环节的长度。
     - \( -1 \)：表示循环节的首尾不算。

---

### **实现与复杂度**

#### **时间复杂度**
- 统计 \( \text{cnt} \) 和 \( k \)：\( O(n) \)。
- 计算公式：\( O(1) \)。
- 整体复杂度：\( O(n) \)。



### **总结**

- **核心思路**：将频率最高的数字作为循环节，在循环节之间插入其他数字。
- **公式推导**：利用数学公式快速计算最优排列的所需长度。
- **复杂度**：算法效率为 \( O(n) \)，适合大规模数据。