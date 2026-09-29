#include <stdio.h>
#define SIZE 7

int table[SIZE];

void init() { for (int i = 0; i < SIZE; i++) table[i] = -1; }

void insert(int key) {
    int idx = key % SIZE;
    while (table[idx] != -1) idx = (idx + 1) % SIZE;
    table[idx] = key;
}

void display() {
    printf("Hash Table (Linear Probing):\n");
    for (int i = 0; i < SIZE; i++) {
        if (table[i] != -1) printf("Index %d: %d\n", i, table[i]);
        else printf("Index %d: ~\n", i);
    }
}

int main() {
    init();
    insert(10); insert(20); insert(30); insert(25);
    display();
    return 0;
}