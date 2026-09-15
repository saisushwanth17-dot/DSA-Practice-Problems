#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void insert_Data(struct node **head, int val) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = val;
    new_node->next = NULL;
    if (*head == NULL) {
        *head = new_node;
        return;
    }
    struct node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = new_node;
}

void delete_Alt(struct node **head) {
    if (*head == NULL) return;
    struct node *prev = *head;
    struct node *curr = (*head)->next;

    while (prev != NULL && curr != NULL) {
        prev->next = curr->next;
        free(curr);
        prev = prev->next;
        if (prev != NULL) {
            curr = prev->next;
        }
    }
}

void printList(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) printf(" ");
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        struct node *head = NULL;
        for (int i = 1; i <= n; i++) {
            insert_Data(&head, i);
        }
        delete_Alt(&head);
        printList(head);
    }
    return 0;
}
