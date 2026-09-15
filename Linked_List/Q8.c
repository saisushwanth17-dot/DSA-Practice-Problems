#include <stdio.h>
#include <stdlib.h>

struct node {
    int data;
    struct node *next;
};

void create(struct node **head, int data) {
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    new_node->data = data;
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

void print(struct node *head) {
    struct node *temp = head;
    while (temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void fold(struct node *head) {
    int arr[100];
    int n = 0;
    struct node *temp = head;
    while (temp != NULL) {
        arr[n++] = temp->data;
        temp = temp->next;
    }

    int left = 0, right = n - 1;
    printf("Link list data after fold:");
    while (left <= right) {
        if (left == right) {
            printf("%d ", arr[left]);
        } else {
            printf("%d %d ", arr[left], arr[right]);
        }
        left++;
        right--;
    }
    printf("\n");
}

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        struct node *head = NULL;
        for (int i = 0; i < n; i++) {
            int val;
            scanf("%d", &val);
            create(&head, val);
        }
        printf("Link list data:");
        print(head);
        fold(head);
    }
    return 0;
}
