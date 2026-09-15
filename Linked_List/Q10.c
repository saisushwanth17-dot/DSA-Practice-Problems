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

void delFirstK(int k) {
    for (int i = 0; i < k && start != NULL; i++) {
        struct node *temp = start;
        start = start->next;
        free(temp);
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
        int k;
        scanf("%d", &k);
        delFirstK(k);
        display();
    }
    return 0;
}
