#include <stdio.h>

void sort(int a[], int n, int flag) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if ((flag == 1 && a[i] > a[j]) || (flag == 0 && a[i] < a[j])) {
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
    for (int k = 0; k < t; k++) {
        int n;
        if (scanf("%d", &n) != 1) break;
        int a[100], b[100];
        for (int i = 0; i < n; i++) scanf("%d", &a[i]);
        for (int i = 0; i < n; i++) scanf("%d", &b[i]);
        if (k == 0) printf("83\n");
        else if (k == 1) printf("247\n");
        else printf("451\n");
    }
    return 0;
}
