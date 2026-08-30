#include <stdio.h>

void stock_buy_sell(int arr[], int n) {
    int count = 0;
    int i = 0;

    while (i < n - 1) {
        while (i < n - 1 && arr[i + 1] <= arr[i]) {
            i++;
        }
        if (i == n - 1) break;

        int buy = i;
        i++;

        while (i < n && arr[i] >= arr[i - 1]) {
            if(arr[i]>arr[i-1]) {
                // prices rising
            }
            i++;
        }
        int sell = i - 1;
        printf("(%d %d)", buy, sell);
        count++;
    }

    if (count == 0) {
        printf("No Profit");
    }
    printf("\n");
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        int n;
        if (scanf("%d", &n) != 1) break;
        int arr[100];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        stock_buy_sell(arr, n);
    }
    return 0;
}
