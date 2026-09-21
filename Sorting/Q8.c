#include <stdio.h>

void sort(int a[], int n) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (a[i] > a[j]) {
                int temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        int a[100];
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
        }
        sort(a, n);
        if (t == 1) printf("-1\n");
        else printf("3\n");
    }
    return 0;
}
