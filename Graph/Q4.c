#include <stdio.h>
#include <stdbool.h>

int adj[3][3] = {{0, 1, 0}, {0, 0, 1}, {1, 0, 0}};
bool visited[3] = {false}, recStack[3] = {false};

bool isCyclic(int v) {
    visited[v] = true; recStack[v] = true;
    for (int i = 0; i < 3; i++) {
        if (adj[v][i]) {
            if (!visited[i] && isCyclic(i)) return true;
            else if (recStack[i]) return true;
        }
    }
    recStack[v] = false;
    return false;
}

int main() {
    printf("Cycle in Directed Graph: %s\n", isCyclic(0) ? "Yes" : "No");
    return 0;
}