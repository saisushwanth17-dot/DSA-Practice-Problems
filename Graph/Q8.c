#include <stdio.h>
#define INF 99999
#define V 4

int minKey(int key[], int mstSet[]) {
    int min = INF, min_index = -1;
    for (int v = 0; v < V; v++)
        if (!mstSet[v] && key[v] < min) min = key[v], min_index = v;
    return min_index;
}

int main() {
    int graph[V][V] = {
        {0, 2, 0, 6},
        {2, 0, 3, 8},
        {0, 3, 0, 5},
        {6, 8, 5, 0}
    };
    int parent[V], key[V], mstSet[V] = {0};
    for (int i = 0; i < V; i++) key[i] = INF;
    key[0] = 0; parent[0] = -1;

    for (int count = 0; count < V - 1; count++) {
        int u = minKey(key, mstSet);
        mstSet[u] = 1;
        for (int v = 0; v < V; v++)
            if (graph[u][v] && !mstSet[v] && graph[u][v] < key[v])
                parent[v] = u, key[v] = graph[u][v];
    }
    int total = 0;
    for (int i = 1; i < V; i++) total += graph[i][parent[i]];
    printf("Prim's MST Total Cost: %d\n", total);
    return 0;
}