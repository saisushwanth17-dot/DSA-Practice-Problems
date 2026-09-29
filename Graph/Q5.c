#include <stdio.h>

int parent[3] = {0, 1, 2};

int find(int i) {
    if (parent[i] == i) return i;
    return parent[i] = find(parent[i]);
}

void union_sets(int x, int y) {
    int xroot = find(x), yroot = find(y);
    parent[xroot] = yroot;
}

int main() {
    int edges[3][2] = {{0, 1}, {1, 2}, {0, 2}};
    int has_cycle = 0;
    for (int i = 0; i < 3; i++) {
        int x = find(edges[i][0]), y = find(edges[i][1]);
        if (x == y) { has_cycle = 1; break; }
        union_sets(x, y);
    }
    printf("Graph Contains Cycle: %s\n", has_cycle ? "True" : "False");
    return 0;
}