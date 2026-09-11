#include <stdio.h>

int q[100];
int front = 0, rear = -1;

void enqueue(int data) {
    q[++rear] = data;
}

void display() {
    int i;
    for(i=front;i<=rear;i++) {
        printf("%d ", q[i]);
    }
}

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        front = 0; rear = -1;
        for (int i = 0; i < n; i++) {
            int data;
            scanf("%d", &data);
            printf("Enqueuing %d\n", data);
            enqueue(data);
            display();
            if (i < n - 1) printf(" ");
        }
        printf("\n");
    }
    return 0;
}
