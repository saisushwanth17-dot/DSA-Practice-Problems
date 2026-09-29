#include <stdio.h>

int BIT[100] = {0}, n = 12;

void update(int idx, int val) {
    for (; idx <= n; idx += idx & -idx) BIT[idx] += val;
}

int query(int idx) {
    int sum = 0;
    for (; idx > 0; idx -= idx & -idx) sum += BIT[idx];
    return sum;
}

int main() {
    int arr[] = {0, 2, 1, 1, 3, 2, 3, 4, 5, 6, 7, 8, 9};
    for (int i = 1; i <= n; i++) update(i, arr[i]);
    printf("Prefix Sum of first 5 elements: %d\n", query(5));
    return 0;
}