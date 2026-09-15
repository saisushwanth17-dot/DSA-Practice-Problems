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
    struct node *p1 = start;
    int found = 0;
    while (p1 != NULL) {
        if (p1->data == key) {
            found = 1;
            break;
        }
        p1 = p1->next;
    }

    if (!found) {
        printf("Invalid Node! ");
    } else {
        while (start != NULL && start->data != key) {
            struct node *temp = start;
            start = start->next;
            free(temp);
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
