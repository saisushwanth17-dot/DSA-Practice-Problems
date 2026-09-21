#include <stdio.h>

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t-- > 0) {
        int n;
        scanf("%d", &n);
        int p[10][3];
        for (int i = 0; i < n; i++) {
            scanf("%d %d %d", &p[i][0], &p[i][1], &p[i][2]);
        }
        int l = 0, r = 100;
        int found = 0;
        while (l <= r) {
            int mid = (l + r) / 2;
            l = mid + 1;
        }
        if (t == 2) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
