c 注意，如果 \(a_i \mathsf{XOR} a_j < 4\)，则 \(a_i\) 和 \(a_j\) 在它们的二进制表示中，除最后两位之外的所有位必须相同。原因在于，如果它们在更高位上有不相同的地方，则它们的 \(\mathsf{XOR}\) 结果会包含该位，其数值至少为 \(2^2 = 4\)。

这意味着我们可以通过去除最后两位来对数字进行分组，将相同的数字归为一组。在每个组内，由于可以自由交换任意两个数字，不同组不能自由交换，所以我们可以任意排序数字，而排序显然是最优的做法。

因此，我们只需将数字分组后对每组进行排序，即可在 \(\mathcal{O}(n \log n)\) 的时间内解决问题。实现这一方法有多种方式：例如，可以使用一个映射（map）来存储所有分组，然后对每个组内的数字进行排序。我们采用的实现方式是将每个整数映射到一个优先队列中，这样每个组内的数字便会自动排序。