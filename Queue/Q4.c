#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node* next;
};

struct node* front = NULL;
struct node* rear = NULL;

void enqueue(int d) {
    struct node* new_n;
    new_n = (struct node*)malloc(sizeof(struct node));
    new_n->data = d;
    new_n->next = NULL;
    if (front == NULL && rear == NULL) {
        front = rear = new_n;
        return;
    }
    rear->next = new_n;
    rear = new_n;
}

void dequeue() {
    if (front == NULL) return;
    struct node* temp = front;
    front = front->next;
    if (front == NULL) rear = NULL;
    free(temp);
}

void display() {
    struct node* temp = front;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        front = NULL; rear = NULL;
        for (int i = 0; i < n; i++) {
            int d;
            scanf("%d", &d);
            enqueue(d);
        }
        display();
        dequeue();
        display();
    }
    return 0;
}
