#include <stdio.h>

#define SIZE 20

typedef struct Queue {
    int arr[SIZE];
    int front;
    int rear;
} Queue;

void enQueue(Queue* q, int value) {
    if ((q->front == 0 && q->rear == SIZE - 1) || (q->rear == (q->front - 1) % (SIZE - 1))) {
        return;
    }
    if (q->front == -1) {
        q->front = q->rear = 0;
    } else if (q->rear == SIZE - 1 && q->front != 0) {
        q->rear = 0;
    } else {
        q->rear++;
    }
    q->arr[q->rear] = value;
}

int deQueue(Queue* q) {
    if (q->front == -1) return -1;
    int data = q->arr[q->front];
    if (q->front == q->rear) {
        q->front = q->rear = -1;
    } else if (q->front == SIZE - 1) {
        q->front = 0;
    } else {
        q->front++;
    }
    return data;
}

void displayQueue(struct Queue* q) {
    if (q->front == -1) return;
    printf("Elements in Circular Queue are:");
    if (q->rear >= q->front) {
        for (int i = q->front; i <= q->rear; i++) {
            printf("%d", q->arr[i]);
            if (i < q->rear) printf(" ");
        }
    } else {
        for (int i = q->front; i < SIZE; i++) printf("%d ", q->arr[i]);
        for (int i = 0; i <= q->rear; i++) {
            printf("%d", q->arr[i]);
            if (i < q->rear) printf(" ");
        }
    }
    printf("\n");
}

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        Queue q;
        q.front = -1;
        q.rear = -1;
        for (int i = 0; i < n; i++) {
            int val;
            scanf("%d", &val);
            enQueue(&q, val);
        }
        displayQueue(&q);
        printf("Deleted value = %d\n", deQueue(&q));
        printf("Deleted value = %d", deQueue(&q));
        displayQueue(&q);
    }
    return 0;
}
