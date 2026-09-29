#include <stdio.h>

int adj[4][4] = {{0, 1, 1, 0}, {1, 0, 1, 0}, {1, 1, 0, 1}, {0, 0, 1, 0}};
int visited[4] = {0}, queue[10], f = 0, r = 0;

void bfs(int start) {
    visited[start] = 1;
    queue[r++] = start;
    printf("BFS Traversal: ");
    while (f < r) {
        int u = queue[f++];
        printf("%d ", u);
        for (int v = 0; v < 4; v++) {
            if (adj[u][v] && !visited[v]) {
                visited[v] = 1;
                queue[r++] = v;
            }
        }
    }
    printf("\n");
}

int main() {
    bfs(2);
    return 0;
}