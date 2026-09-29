#include <stdio.h>

int heap[100], sz = 0;

void push(int x) {
    heap[sz] = x;
    int i = sz++;
    while (i > 0 && heap[(i - 1) / 2] < heap[i]) {
        int t = heap[i]; heap[i] = heap[(i - 1) / 2]; heap[(i - 1) / 2] = t;
        i = (i - 1) / 2;
    }
}

int pop() {
    int top = heap[0];
    heap[0] = heap[--sz];
    int i = 0;
    while (2 * i + 1 < sz) {
        int l = 2 * i + 1, r = 2 * i + 2, largest = i;
        if (l < sz && heap[l] > heap[largest]) largest = l;
        if (r < sz && heap[r] > heap[largest]) largest = r;
        if (largest != i) { int t = heap[i]; heap[i] = heap[largest]; heap[largest] = t; i = largest; }
        else break;
    }
    return top;
}

int main() {
    push(10); push(30); push(20); push(40);
    printf("Top Priority Element: %d\n", pop());
    printf("Next Priority Element: %d\n", pop());
    return 0;
}