#include <stdio.h>

int heap[100], sz = 0;

void swap(int *a, int *b) { int t = *a; *a = *b; *b = t; }

void insert_min_heap(int val) {
    heap[sz] = val;
    int i = sz++;
    while (i != 0 && heap[(i - 1) / 2] > heap[i]) {
        swap(&heap[i], &heap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

int extract_min() {
    if (sz <= 0) return -1;
    if (sz == 1) return heap[--sz];
    int root = heap[0];
    heap[0] = heap[--sz];
    int i = 0;
    while (2 * i + 1 < sz) {
        int left = 2 * i + 1, right = 2 * i + 2, smallest = i;
        if (left < sz && heap[left] < heap[smallest]) smallest = left;
        if (right < sz && heap[right] < heap[smallest]) smallest = right;
        if (smallest != i) { swap(&heap[i], &heap[smallest]); i = smallest; }
        else break;
    }
    return root;
}

int main() {
    int keys[] = {3, 2, 1, 15, 5, 4, 45};
    for (int i = 0; i < 7; i++) insert_min_heap(keys[i]);
    printf("Extracted Min: %d\n", extract_min());
    printf("Next Min: %d\n", extract_min());
    return 0;
}