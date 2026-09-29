#include <stdio.h>
#include <stdlib.h>

struct Edge { int src, dest, weight; };

int compare(const void* a, const void* b) {
    return ((struct Edge*)a)->weight - ((struct Edge*)b)->weight;
}

int find(int parent[], int i) {
    if (parent[i] == -1) return i;
    return find(parent, parent[i]);
}

int main() {
    struct Edge edges[] = {{0, 1, 10}, {0, 2, 6}, {0, 3, 5}, {1, 3, 15}, {2, 3, 4}};
    qsort(edges, 5, sizeof(struct Edge), compare);
    int parent[4] = {-1, -1, -1, -1}, mst_wt = 0;

    for (int i = 0; i < 5; i++) {
        int x = find(parent, edges[i].src), y = find(parent, edges[i].dest);
        if (x != y) {
            mst_wt += edges[i].weight;
            parent[x] = y;
        }
    }
    printf("Kruskal MST Total Weight: %d\n", mst_wt);
    return 0;
}