#include <stdio.h>

int main() {
    int in_degree[6] = {2, 2, 1, 1, 0, 0};
    int adj[6][6] = {0};
    adj[5][2] = adj[5][0] = adj[4][0] = adj[4][1] = adj[2][3] = adj[3][1] = 1;

    int q[10], f = 0, r = 0;
    for (int i = 0; i < 6; i++) if (in_degree[i] == 0) q[r++] = i;

    printf("Topological Sort: ");
    while (f < r) {
        int u = q[f++];
        printf("%d ", u);
        for (int v = 0; v < 6; v++) {
            if (adj[u][v]) {
                if (--in_degree[v] == 0) q[r++] = v;
            }
        }
    }
    printf("\n");
    return 0;
}