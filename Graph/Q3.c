#include <stdio.h>

int adj[4][4] = {{0, 1, 1, 0}, {1, 0, 1, 0}, {1, 1, 0, 1}, {0, 0, 1, 0}};
int visited[4] = {0};

void dfs(int u) {
    visited[u] = 1;
    printf("%d ", u);
    for (int v = 0; v < 4; v++) {
        if (adj[u][v] && !visited[v]) dfs(v);
    }
}

int main() {
    printf("DFS Traversal: ");
    dfs(2);
    printf("\n");
    return 0;
}