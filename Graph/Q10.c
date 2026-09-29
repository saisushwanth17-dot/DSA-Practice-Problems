#include <stdio.h>
#define INF 99999

struct Edge { int u, v, w; };

int main() {
    int V = 5, E = 8;
    struct Edge edges[] = {
        {0, 1, -1}, {0, 2, 4}, {1, 2, 3}, {1, 3, 2},
        {1, 4, 2}, {3, 2, 5}, {3, 1, 1}, {4, 3, -3}
    };
    int dist[5] = {0, INF, INF, INF, INF};

    for (int i = 1; i <= V - 1; i++) {
        for (int j = 0; j < E; j++) {
            int u = edges[j].u, v = edges[j].v, w = edges[j].w;
            if (dist[u] != INF && dist[u] + w < dist[v])
                dist[v] = dist[u] + w;
        }
    }
    printf("Vertex Distances from Source 0:\n");
    for (int i = 0; i < V; i++) printf("Vertex %d: %d\n", i, dist[i]);
    return 0;
}