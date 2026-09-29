#include <stdio.h>

int tree[100], lazy[100];

void update_range(int node, int start, int end, int l, int r, int val) {
    if (lazy[node] != 0) {
        tree[node] += (end - start + 1) * lazy[node];
        if (start != end) { lazy[2 * node] += lazy[node]; lazy[2 * node + 1] += lazy[node]; }
        lazy[node] = 0;
    }
    if (start > end || start > r || end < l) return;
    if (start >= l && end <= r) {
        tree[node] += (end - start + 1) * val;
        if (start != end) { lazy[2 * node] += val; lazy[2 * node + 1] += val; }
        return;
    }
    int mid = (start + end) / 2;
    update_range(2 * node, start, mid, l, r, val);
    update_range(2 * node + 1, mid + 1, end, l, r, val);
    tree[node] = tree[2 * node] + tree[2 * node + 1];
}

int main() {
    update_range(1, 0, 5, 1, 3, 10);
    printf("Lazy Propagation Range Update executed successfully.\n");
    return 0;
}