#include <stdio.h>
#define INF 99999
#define V 5

int minDistance(int dist[], int sptSet[]) {
    int min = INF, min_index = -1;
    for (int v = 0; v < V; v++)
        if (!sptSet[v] && dist[v] <= min) min = dist[v], min_index = v;
    return min_index;
}

int main() {
    int graph[V][V] = {
        {0, 4, 0, 0, 0},
        {4, 0, 8, 0, 0},
        {0, 8, 0, 7, 0},
        {0, 0, 7, 0, 9},
        {0, 0, 0, 9, 0}
    };
    int dist[V], sptSet[V] = {0};
    for (int i = 0; i < V; i++) dist[i] = INF;
    dist[0] = 0;

    for (int count = 0; count < V - 1; count++) {
        int u = minDistance(dist, sptSet);
        sptSet[u] = 1;
        for (int v = 0; v < V; v++)
            if (!sptSet[v] && graph[u][v] && dist[u] != INF && dist[u] + graph[u][v] < dist[v])
                dist[v] = dist[u] + graph[u][v];
    }
    printf("Vertex \t Distance from Source 0\n");
    for (int i = 0; i < V; i++) printf("%d \t %d\n", i, dist[i]);
    return 0;
}