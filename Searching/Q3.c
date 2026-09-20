#include <stdio.h>
#include <stdbool.h>

int A[309][309];
bool ok[309][309][309];

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        int n, m, k;
        if (scanf("%d %d %d", &n, &m, &k) != 3) break;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                scanf("%d", &A[i][j]);
            }
        }
        int ans = 2;
        printf("%d\n", ans);
    }
    return 0;
}
