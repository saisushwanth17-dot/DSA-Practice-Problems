#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int arr[], int no) {
    for (int i = 0; i < no - 1; i++) {
        for (int j = 0; j < no - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int MEGA_SALE(int arr[], int no, int k) {
    bubble_sort(arr, no);
    int sum = 0;
    for (int i = 0; i < k; i++) {
        if (arr[i] < 0) {
            sum += abs(arr[i]);
        }
    }
    return sum;
}

int main() {
    int t;
    if (scanf("%d", &t) != 1) return 0;
    while (t--) {
        int n, k;
        scanf("%d %d", &n, &k);
        int arr[100];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        printf("%d\n", MEGA_SALE(arr, n, k));
    }
    return 0;
}
