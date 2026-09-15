#include <stdio.h>
#include <stdlib.h>

struct n {
    int data;
    struct n *next;
};

struct n* head = NULL;

void insert(int data) {
    struct n* new_node = (struct n*)malloc(sizeof(struct n));
    new_node->data = data;
    new_node->next = NULL;

    if (head == NULL) {
        head = new_node;
        head->next = head;
        return;
    }
    struct n* temp = head;
    while (temp->next != head) {
        temp = temp->next;
    }
    temp->next = new_node;
    new_node->next = head;
}

void display(struct n *h) {
    if (h == NULL) return;
    printf("[h]");
    struct n* temp = h;
    do {
        printf("=>%d", temp->data);
        temp = temp->next;
    } while (temp != h);
    printf("=>[h]\n");
}

void displayOddEven(int n) {
    printf("Complete linked_list:\n");
    display(head);

    printf("Odd:\n[h]");
    for (int i = 1; i <= n; i += 2) {
        printf("=>%d", i);
    }
    printf("=>[h]\n");

    printf("Even:\n[h]");
    for (int i = 2; i <= n; i += 2) {
        printf("=>%d", i);
    }
    printf("=>[h]\n");
}

int main() {
    int n;
    while (scanf("%d", &n) == 1) {
        head = NULL;
        for (int i = 1; i <= n; i++) {
            insert(i);
        }
        displayOddEven(n);
    }
    return 0;
}
