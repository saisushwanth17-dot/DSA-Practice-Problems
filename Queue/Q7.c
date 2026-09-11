#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node *f = NULL;
struct node *r = NULL;

void enqueue(int d) {
    struct node* n;
    n = (struct node*)malloc(sizeof(struct node));
    n->data = d;
    n->next = NULL;
    if (f == NULL && r == NULL) {
        f = r = n;
        return;
    }
    r->next = n;
    r = n;
}

void display() {
    struct node* t = f;
    while (t != NULL) {
        printf("%d\n", t->data);
        t = t->next;
    }
}

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        f = NULL; r = NULL;
        for (int i = 0; i < n; i++) {
            int d;
            scanf("%d", &d);
            enqueue(d);
        }
        display();
    }
    return 0;
}
