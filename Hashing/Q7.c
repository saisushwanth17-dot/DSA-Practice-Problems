#include <stdio.h>

void print_duplicates(int arr[], int n) {
    int count[100] = {0};
    for (int i = 0; i < n; i++) count[arr[i]]++;
    printf("Duplicate Elements: ");
    for (int i = 0; i < 100; i++) {
        if (count[i] > 1) printf("%d ", i);
    }
    printf("\n");
}

int main() {
    int arr[] = {2, 3, 4, 5, 6, 7, 3, 4, 2, 7, 6, 8, 6, 4, 9};
    print_duplicates(arr, 15);
    return 0;
}