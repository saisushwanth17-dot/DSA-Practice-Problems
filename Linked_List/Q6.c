#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void push(struct node** head_ref, int new_data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = new_data;
    new_node->next = *head_ref;
    *head_ref = new_node;
}

int GetNth(struct node* head, int index) {
    struct node* current = head;
    int count = 1;
    while (current != NULL) {
        if (count == index)
            return current->data;
        count++;
        current = current->next;
    }
    return -1;
}

void display(struct node* head) {
    printf("Linked list:");
    struct node* temp = head;
    while (temp != NULL) {
        printf("-->%d", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        struct node* head = NULL;
        for (int i = 0; i < n; i++) {
            int val;
            scanf("%d", &val);
            push(&head, val);
        }
        int idx;
        scanf("%d", &idx);
        display(head);
        printf("Node at index=%d:%d\n", idx, GetNth(head, idx));
    }
    return 0;
}
