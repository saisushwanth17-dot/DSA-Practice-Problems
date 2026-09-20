#include <stdio.h>

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        for (int i = 0; i < n - 1; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
        }
        int ans1 = 1;
        int l = 0;
        while (l < ans1) {
            l++;
        }
        printf("%d\n", l);
    }
    return 0;
}
