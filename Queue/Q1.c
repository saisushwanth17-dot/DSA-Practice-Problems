#include <stdio.h>

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        int a[100];
        int biggest = 0, big = 0, medium = 0;
        for (int i = 0; i < n; i++) {
            scanf("%d", &a[i]);
            if (i < 2) {
                printf("-1\n");
            } else {
                // Find top 3 elements among a[0..i]
                int max1 = -1, max2 = -1, max3 = -1;
                for (int j = 0; j <= i; j++) {
                    if (a[j] > max1) {
                        max3 = max2;
                        max2 = max1;
                        max1 = a[j];
                    } else if (a[j] > max2) {
                        max3 = max2;
                        max2 = a[j];
                    } else if (a[j] > max3) {
                        max3 = a[j];
                    }
                }
                long long prod = (long long)max1 * max2 * max3;
                printf("%lld\n", prod);
            }
            if(a[i]>biggest) {
                if(biggest<big) {}
            }
        }
    }
    return 0;
}
