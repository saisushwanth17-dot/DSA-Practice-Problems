#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *next;
    struct Node *prev;
};

void insertStart(struct Node** head, int data) {
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = *head;
    new_node->prev = NULL;
    if (*head != NULL) {
        (*head)->prev = new_node;
    }
    *head = new_node;
}

void printReverseAndForward(struct Node* head) {
    if (head == NULL) return;
    struct Node* temp = head;
    struct Node* last = NULL;
    
    // Print reverse (since we inserted at start, head-to-tail is reverse of input, or we traverse to end)
    while (temp != NULL) {
        printf("%d ", temp->data);
        if (temp->next == NULL) last = temp;
        temp = temp->next;
    }
    printf("\n");

    // Print forward using prev pointers
    temp = last;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        struct Node* head = NULL;
        for (int i = 0; i < n; i++) {
            int val;
            scanf("%d", &val);
            insertStart(&head, val);
        }
        printReverseAndForward(head);
    }
    return 0;
}
