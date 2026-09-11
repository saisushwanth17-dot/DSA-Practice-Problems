#include <stdio.h>

#define SIZE 20
int arr[SIZE];
int top1 = -1;
int top2 = SIZE;

void push1(int x) {
    if (top1 < top2 - 1) {
        arr[++top1] = x;
    }
}

void push2(int x) {
    if (top1 < top2 - 1) {
        arr[--top2] = x;
    }
}

int pop1() {
    if (top1 >= 0) {
        return arr[top1--];
    }
    return -1;
}

int pop2() {
    if (top2 < SIZE) {
        return arr[top2++];
    }
    return -1;
}

int main() {
    int v1, v2, v3, v4, v5;
    if (scanf("%d %d %d %d %d", &v1, &v2, &v3, &v4, &v5) == 5) {
        push1(v1);
        push1(v2);
        push1(v5);
        push2(v3);
        push2(v4);
        printf("Popped element from stack1 is:%d\n", pop1());
        printf("Popped element from stack2 is:%d\n", pop2());
    }
    return 0;
}
