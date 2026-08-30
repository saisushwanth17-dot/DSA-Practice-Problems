#include <stdio.h>

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        int m, n;
        if (scanf("%d %d", &m, &n) != 2) break;
        int C[m][n];
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &C[i][j]);
            }
        }
        int x1, y1, x2, y2;
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        int sum = 0;
        for (int i = x1 - 1; i <= x2 - 1; i++) {
            for (int j = y1 - 1; j <= y2 - 1; j++) {
                sum += C[i][j];
            }
        }
        printf("%d\n", sum);
    }
    return 0;
}
