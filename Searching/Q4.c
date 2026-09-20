#include <stdio.h>
#include <stdlib.h>

int search(int a, int b) {
    return abs(a - b);
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        int a, b;
        scanf("%d %d", &a, &b);
        printf("%d\n", search(a, b));
    }
    return 0;
}
