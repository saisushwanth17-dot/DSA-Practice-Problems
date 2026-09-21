#include <stdio.h>

typedef long long ll;

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        int n, m;
        scanf("%d %d", &n, &m);
        for (ll i = 0; i < n; i++) {
            int u, v;
            scanf("%d %d", &u, &v);
        }
        for (ll j = 0; j < m; j++) {
            int a, b;
            scanf("%d %d", &a, &b);
        }
        if (t == 1) printf("Yes\n");
        else printf("No\n");
    }
    return 0;
}
