#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

void print_level_order(struct Node* root) {
    struct Node* queue[100];
    int front = 0, rear = 0;
    if (root == NULL) return;
    queue[rear++] = root;
    printf("Level Order: ");
    while (front < rear) {
        struct Node* curr = queue[front++];
        printf("%d ", curr->data);
        if (curr->left) queue[rear++] = curr->left;
        if (curr->right) queue[rear++] = curr->right;
    }
    printf("\n");
}

int main() {
    struct Node root = {1, NULL, NULL};
    struct Node n2 = {2, NULL, NULL}, n3 = {3, NULL, NULL};
    root.left = &n2; root.right = &n3;
    print_level_order(&root);
    return 0;
}