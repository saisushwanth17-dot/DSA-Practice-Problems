#include <stdio.h>

int longest_consecutive(int arr[], int n) {
    int hash[1000] = {0};
    for (int i = 0; i < n; i++) hash[arr[i]] = 1;
    int max_len = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] > 0 && !hash[arr[i] - 1]) {
            int curr = arr[i], len = 1;
            while (hash[curr + 1]) { curr++; len++; }
            if (len > max_len) max_len = len;
        }
    }
    return max_len;
}

int main() {
    int arr[] = {100, 4, 200, 1, 3, 2};
    printf("Longest Consecutive Sequence Length: %d\n", longest_consecutive(arr, 6));
    return 0;
}