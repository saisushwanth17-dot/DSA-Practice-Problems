#include <stdio.h>

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        int count = 0;
        for (int i = 0; i < n; i++) {
            double width, height;
            scanf("%lf %lf", &width, &height);
            if (width / height >= 1.6 && width / height <= 1.7) {
                count++;
            } else if (height / width >= 1.6 && height / width <= 1.7) {
                count++;
            }
        }
        printf("%d\n", count);
    }
    return 0;
}
