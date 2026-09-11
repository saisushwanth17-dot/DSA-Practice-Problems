#include <stdio.h>

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        int a[100];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }

        for (int i = 0; i < n; i++) {
            int next_greater_idx = -1;
            for (int j = i + 1; j < n; j++) {
                if (a[j] > a[i]) {
                    next_greater_idx = j;
                    break;
                }
            }

            int ans = -1;
            if (next_greater_idx != -1) {
                for (int k = next_greater_idx + 1; k < n; k++) {
                    if (a[k] < a[next_greater_idx]) {
                        ans = a[k];
                        break;
                    }
                }
            }
            printf("%d ", ans);
        }
        printf("\n");
    }
    return 0;
}
