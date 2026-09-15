#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

struct node *start = NULL;

void create(int val) {
    struct node *new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->next = NULL;
    if (start == NULL) {
        start = new_node;
        return;
    }
    struct node *temp = start;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void insertBefore(int key, int val) {
    struct node *p1 = (struct node*)malloc(sizeof(struct node));
    p1->data = val;
    p1->next = NULL;

    if (start == NULL) {
        printf("Node not found!\n");
        return;
    }
    if (start->data == key) {
        p1->next = start;
        start = p1;
        return;
    }
    struct node *p2 = start;
    while (p2->next != NULL && p2->next->data != key) {
        p2 = p2->next;
    }
    if (p2->next == NULL) {
        printf("Node not found!\n");
        free(p1);
    } else {
        p1->next = p2->next;
        p2->next = p1;
    }
}

void display() {
    printf("Linked List:");
    struct node *temp = start;
    while (temp != NULL) {
        printf("->%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        start = NULL;
        for (int i = 0; i < n; i++) {
            int val;
            scanf("%d", &val);
            create(val);
        }
        int key, val;
        scanf("%d %d", &key, &val);
        insertBefore(key, val);
        display();
    }
    return 0;
}
