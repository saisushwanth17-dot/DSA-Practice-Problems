#include <stdio.h>

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        int arr[100];
        int st[100];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }

        int max_val = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (arr[i] < arr[j]) {
                    st[i] = arr[i] ^ arr[j];
                    if (st[i] > max_val) {
                        max_val = st[i];
                    }
                }
            }
        }
        printf("%d\n", max_val);
    }
    return 0;
}
