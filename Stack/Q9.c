#include <stdio.h>

int q[100];
int front = 0, rear = -1;

void push(int val) {
    q[++rear] = val;
}

int pop() {
    if (rear >= front) {
        return q[rear--];
    }
    return -1;
}

int top() {
    if (rear >= front) {
        return q[rear];
    }
    return -1;
}

int main() {
    int n, pops;
    while (scanf("%d %d", &n, &pops) == 2) {
        front = 0; rear = -1;
        for (int i = 0; i < n; i++) {
            int val;
            scanf("%d", &val);
            push(val);
        }
        printf("top of element %d\n", top());
        for (int i = 0; i < pops; i++) {
            pop();
        }
        printf("top of element %d\n", top());
    }
    return 0;
}
