#include <stdio.h>
#include <stdlib.h>
#define SIZE 7

struct Node { int data; struct Node *next; };
struct Node *chain[SIZE];

void insert_chain(int val) {
    int idx = val % SIZE;
    struct Node *n = (struct Node*)malloc(sizeof(struct Node));
    n->data = val; n->next = chain[idx];
    chain[idx] = n;
}

int main() {
    for (int i = 0; i < SIZE; i++) chain[i] = NULL;
    insert_chain(15); insert_chain(11); insert_chain(27); insert_chain(8);
    printf("Separate Chaining Table:\n");
    for (int i = 0; i < SIZE; i++) {
        printf("Bucket %d: ", i);
        for (struct Node *t = chain[i]; t; t = t->next) printf("-> %d ", t->data);
        printf("\n");
    }
    return 0;
}