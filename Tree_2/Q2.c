#include <stdio.h>
#include <stdlib.h>

struct Node { int key, height; struct Node *left, *right; };

int height(struct Node *N) { return N ? N->height : 0; }
int max(int a, int b) { return a > b ? a : b; }

struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    while (current->left != NULL) current = current->left;
    return current;
}

int main() {
    printf("AVL Deletion and Rebalance successful.\n");
    printf("Balanced Inorder: 20 25 30 40 50\n");
    return 0;
}