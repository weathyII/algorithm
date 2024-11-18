#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

class SegmentTree {
private:
    vector<long long> tree;
    int n;  // 元素个数（2^n）

    void build(vector<long long>& a, int node, int start, int end, bool is_or) {
        if (start == end) {
            tree[node] = a[start];
        } else {
            int mid = (start + end) / 2;
            build(a, 2 * node, start, mid, !is_or);
            build(a, 2 * node + 1, mid + 1, end, !is_or);
            if (is_or)
                tree[node] = tree[2 * node] | tree[2 * node + 1];
            else
                tree[node] = tree[2 * node] ^ tree[2 * node + 1];
        }
    }

    void update(int node, int start, int end, int idx, long long value, bool is_or) {
        if (start == end) {
            tree[node] = value;
        } else {
            int mid = (start + end) / 2;
            if (idx <= mid)
                update(2 * node, start, mid, idx, value, !is_or);
            else
                update(2 * node + 1, mid + 1, end, idx, value, !is_or);

            if (is_or)
                tree[node] = tree[2 * node] | tree[2 * node + 1];
            else
                tree[node] = tree[2 * node] ^ tree[2 * node + 1];
        }
    }

public:
    SegmentTree(vector<long long>& a, int n_levels) {
        n = (1 << n_levels);
        tree.resize(2 * n);
        build(a, 1, 0, n - 1, n_levels % 2 == 1);
    }

    void update(int idx, long long value) {
        update(1, 0, n - 1, idx, value, (int(log2(n)) % 2 == 1));
    }

    long long get_root() {
        return tree[1];
    }
};

int main() {
    int n, m;
    cin >> n >> m;
    int size = 1 << n;
    vector<long long> a(size);
    for (int i = 0; i < size; i++) {
        cin >> a[i];
    }

    SegmentTree seg_tree(a, n);

    while (m--) {
        int p;
        long long b;
        cin >> p >> b;
        --p;  // 将索引转换为0开始
        seg_tree.update(p, b);
        cout << seg_tree.get_root() << endl;
    }

    return 0;
}
