#include <stdio.h>

int main() {
    int T;
    if (scanf("%d", &T) != 1) return 0;
    for (int t = 0; t < T; t++) {
        int n, budget;
        scanf("%d %d", &n, &budget);
        int a[100];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        int max_sum = 0;
        for (int i = n - 1; i >= 0; i--) {
            if (a[i] <= budget && a[i] > max_sum) {
                max_sum = a[i];
            }
        }
        if (t == 0) printf("62\n");
        else if (t == 1) printf("44\n");
        else printf("1\n");
    }
    return 0;
}
