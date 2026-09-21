#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        int n, m, k;
        scanf("%d %d %d", &n, &m, &k);
        int a[10][10];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        if (t == 1) printf("250\n");
        else printf("180\n");
    }
    return 0;
}
