#include <stdio.h>
#include <stdbool.h>

bool subArrayExists(int arr[], int n) {
    int hash[1000] = {0}, sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        if (sum == 0 || hash[sum + 500]) return true;
        hash[sum + 500] = 1;
    }
    return false;
}

int main() {
    int arr[] = {4, 2, -3, 1, 6};
    printf("Zero Sum Subarray Exists: %s\n", subArrayExists(arr, 5) ? "Yes" : "No");
    return 0;
}