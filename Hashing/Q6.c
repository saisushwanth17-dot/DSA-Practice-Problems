#include <stdio.h>

void find_pair(int arr[], int n, int sum) {
    int hash[1000] = {0};
    for (int i = 0; i < n; i++) {
        int rem = sum - arr[i];
        if (rem >= 0 && hash[rem]) {
            printf("Pair Found: (%d, %d)\n", arr[i], rem);
            return;
        }
        if (arr[i] >= 0) hash[arr[i]] = 1;
    }
    printf("No Pair Found\n");
}

int main() {
    int arr[] = {1, 4, 45, 6, 10, 8}, sum = 16;
    find_pair(arr, 6, sum);
    return 0;
}