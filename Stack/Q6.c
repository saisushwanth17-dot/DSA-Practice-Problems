#include <stdio.h>

void calculateSpan(int price[], int n, int S[]) {
    S[0] = 1;
    for (int i = 1; i < n; i++) {
        S[i] = 1;
        for (int j = i - 1; (j >= 0) && (price[i] >= price[j]); j--) {
            S[i]++;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        int price[100], S[100];
        for (int i = 0; i < n; i++) {
            scanf("%d", &price[i]);
        }
        calculateSpan(price, n, S);
        printArray(S, n);
    }
    return 0;
}
