#include <stdio.h>

int q[100];
int front = 0, rear = -1;

void enqueue(int data) {
    q[++rear] = data;
}

void dequeue() {
    if (front <= rear) {
        front++;
    }
}

void display() {
    int i;
    for(i=front;i<=rear;i++) {
        printf("%d ", q[i]);
    }
    printf("\n");
}

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        front = 0; rear = -1;
        for (int i = 0; i < n; i++) {
            int data;
            scanf("%d", &data);
            enqueue(data);
        }
        printf("Dequeuing elements:\n");
        for (int i = 0; i < n - 1; i++) {
            dequeue();
            display();
        }
    }
    return 0;
}
