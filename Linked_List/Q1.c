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

void del(int key) {
    while (start != NULL && start->data == key) {
        struct node *temp = start;
        start = start->next;
        free(temp);
    }
    struct node *p1 = start;
    while (p1 != NULL && p1->next != NULL) {
        if (p1->next->data == key) {
            struct node *p2 = p1->next;
            p1->next = p2->next;
            free(p2);
        } else {
            p1 = p1->next;
        }
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
        int key;
        scanf("%d", &key);
        del(key);
        display();
    }
    return 0;
}
