#include <stdio.h>

int adj[4][4] = {0};

void add_edge(int u, int v) {
    adj[u][v] = 1;
    adj[v][u] = 1;
}

int main() {
    add_edge(0, 1); add_edge(0, 2); add_edge(1, 2); add_edge(2, 3);
    printf("Adjacency Matrix (4x4):\n");
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) printf("%d ", adj[i][j]);
        printf("\n");
    }
    return 0;
}