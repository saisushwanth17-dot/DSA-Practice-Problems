#include <stdio.h>

int q[100];
int n_elem = 0;

void enqueue(int data, int l) {
    q[n_elem++] = data;
}

void reverse() {
    for (int i = 0; i < n_elem / 2; i++) {
        int temp = q[i];
        q[i] = q[n_elem - 1 - i];
        q[n_elem - 1 - i] = temp;
    }
}

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        n_elem = 0;
        for (int i = 0; i < n; i++) {
            int val;
            scanf("%d", &val);
            enqueue(val, n);
        }
        printf("Queue:");
        for (int i = 0; i < n; i++) printf("%d ", q[i]);
        printf("\n");
        reverse();
        printf("Reversed Queue:");
        for (int i = 0; i < n; i++) printf("%d ", q[i]);
        printf("\n");
    }
    return 0;
}
