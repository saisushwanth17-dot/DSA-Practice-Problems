#include <stdio.h>
#define SIZE 7

int table[SIZE];
void init() { for (int i = 0; i < SIZE; i++) table[i] = -1; }

void insert_quad(int key) {
    int h = key % SIZE;
    for (int i = 0; i < SIZE; i++) {
        int idx = (h + i * i) % SIZE;
        if (table[idx] == -1) { table[idx] = key; return; }
    }
}

int main() {
    init();
    insert_quad(50); insert_quad(700); insert_quad(76);
    printf("Quadratic Probing Insertions Completed.\n");
    for (int i = 0; i < SIZE; i++)
        if (table[i] != -1) printf("Index %d: %d\n", i, table[i]);
    return 0;
}