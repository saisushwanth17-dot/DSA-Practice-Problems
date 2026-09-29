#include <stdio.h>
#define INF 1000000

int min(int a, int b) { return a < b ? a : b; }

void build(int arr[], int tree[], int node, int start, int end) {
    if (start == end) { tree[node] = arr[start]; return; }
    int mid = (start + end) / 2;
    build(arr, tree, 2 * node, start, mid);
    build(arr, tree, 2 * node + 1, mid + 1, end);
    tree[node] = min(tree[2 * node], tree[2 * node + 1]);
}

int query(int tree[], int node, int start, int end, int l, int r) {
    if (r < start || end < l) return INF;
    if (l <= start && end <= r) return tree[node];
    int mid = (start + end) / 2;
    return min(query(tree, 2 * node, start, mid, l, r),
               query(tree, 2 * node + 1, mid + 1, end, l, r));
}

int main() {
    int arr[] = {2, 5, 1, 4, 9, 3}, tree[24];
    build(arr, tree, 1, 0, 5);
    printf("Min in range [1, 4]: %d\n", query(tree, 1, 0, 5, 1, 4));
    return 0;
}