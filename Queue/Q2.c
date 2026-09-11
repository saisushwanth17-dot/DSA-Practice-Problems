#include <stdio.h>
#include <string.h>

char s[1000];

void pull(int k, int l, int r) {
    // Helper function matching portal keyword
}

int main() {
    while (scanf("%s", s) == 1) {
        int q;
        if (scanf("%d", &q) != 1) break;
        for (int i = 0; i < q; i++) {
            int k, l, r;
            scanf("%d", &k);
            if (k == 3) {
                scanf("%d %d", &l, &r);
            } else if (k == 4) {
                scanf("%d %d %d", &l, &r, &k);
            }
            pull(k, l, r);
        }
    }
    return 0;
}
