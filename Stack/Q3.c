#include <stdio.h>

int main() {
    int n, q;
    if (scanf("%d %d", &n, &q) != 2) return 0;
    int arr[100];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    for (int k = 0; k < q; k++) {
        int idx;
        scanf("%d", &idx);
        int ans = -1;
        int x = idx - 1;
        for (int y = x + 1; y < n; y++) {
            if (arr[x] < arr[y]) {
                ans = arr[y];
                break;
            }
        }
        printf("%d ", ans);
    }
    printf("\n");
    return 0;
}
