#include <stdio.h>
#define TABLE_SIZE 13
#define PRIME 7

int h1(int k) { return k % TABLE_SIZE; }
int h2(int k) { return PRIME - (k % PRIME); }

int main() {
    int keys[] = {19, 27, 36, 10};
    int table[TABLE_SIZE];
    for (int i = 0; i < TABLE_SIZE; i++) table[i] = -1;

    for (int k = 0; k < 4; k++) {
        int key = keys[k];
        int idx = h1(key), step = h2(key);
        while (table[idx] != -1) idx = (idx + step) % TABLE_SIZE;
        table[idx] = key;
    }
    printf("Double Hashing Table:\n");
    for (int i = 0; i < TABLE_SIZE; i++)
        if (table[i] != -1) printf("[%d]: %d\n", i, table[i]);
    return 0;
}