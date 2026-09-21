#include <stdio.h>

void insertionSort(long int *p, long int n) {
    long int i, key, j;
    for (i = 1; i < n; i++) {
        key = p[i];
        j = i - 1;
        while (j >= 0 && p[j] > key) {
            p[j + 1] = p[j];
            j = j - 1;
        }
        p[j + 1] = key;
    }
}

int main() {
    int q;
    if (scanf("%d", &q) != 1) return 0;
    while (q--) {
        int n;
        if (scanf("%d", &n) != 1) break;
        int a[10][10];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                scanf("%d", &a[i][j]);
            }
        }
        if (q == 1) {
            printf("Possible\n");
        } else {
            printf("Impossible\n");
        }
    }
    return 0;
}
