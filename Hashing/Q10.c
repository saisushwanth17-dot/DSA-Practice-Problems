#include <stdio.h>

int subarrays_div_by_k(int arr[], int n, int k) {
    int mod_cnt[100] = {0};
    mod_cnt[0] = 1;
    int sum = 0, count = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
        int rem = (sum % k + k) % k;
        count += mod_cnt[rem];
        mod_cnt[rem]++;
    }
    return count;
}

int main() {
    int arr[] = {4, 5, 0, -2, -3, 1};
    int n = 6, k = 5;
    printf("Total Subarrays Divisible by %d: %d\n", k, subarrays_div_by_k(arr, n, k));
    return 0;
}