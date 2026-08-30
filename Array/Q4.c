#include <stdio.h>

int main() {
    int n;
    if (scanf("%d", &n) != 1) return 0;
    int array[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }

    // Step 1: Sort array in ascending order
    for(int i=0;i<n;i++) {
        for (int j = i + 1; j < n; j++) {
            if(array[i]>array[j]) {
                int temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }

    // Step 2: Swap adjacent elements
    for (int i = 0; i < n - 1; i += 2) {
        int temp = array[i];
        array[i] = array[i + 1];
        array[i + 1] = temp;
    }

    // Print result
    for (int i = 0; i < n; i++) {
        printf("%d", array[i]);
        if (i < n - 1) printf(" ");
    }
    printf("\n");
    return 0;
}
