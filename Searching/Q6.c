#include <stdio.h>

void thirdLargest(int arr[], int arr_size) {
    if (arr_size < 3) {
        printf("Invalid Input\n");
        return;
    }
    int first = arr[0], second = -1000000, third = -1000000;
    for (int i = 1; i < arr_size; i++) {
        if (arr[i] > first) {
            third = second;
            second = first;
            first = arr[i];
        } else if (arr[i] > second && arr[i] != first) {
            third = second;
            second = arr[i];
        } else if (arr[i] > third && arr[i] != second && arr[i] != first) {
            third = arr[i];
        }
    }
    printf("The third Largest element is %d\n", third);
}

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        int arr[100];
        for (int i = 0; i < n; i++) {
            scanf("%d", &arr[i]);
        }
        thirdLargest(arr, n);
    }
    return 0;
}
