#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int a[100];
    for (int k = 0; k < n; k++) {
        scanf("%d", &a[k]);
    }

    int i = 0, j = n - 1;
    while (i < n && j >= 0) {
        if (a[i] > a[j]) {
            printf("1 ");
            j--;
        } else if (a[i] < a[j]) {
            printf("2 ");
            i++;
        } else {
            printf("0 ");
            i++;
            j--;
        }
    }
    printf("\n");
    return 0;
}
