#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

struct Node { int data; struct Node *left, *right; };

bool is_bst_util(struct Node* node, long min, long max) {
    if (node == NULL) return true;
    if (node->data <= min || node->data >= max) return false;
    return is_bst_util(node->left, min, node->data) && is_bst_util(node->right, node->data, max);
}

int main() {
    struct Node root = {2, NULL, NULL}, l = {1, NULL, NULL}, r = {3, NULL, NULL};
    root.left = &l; root.right = &r;
    printf("Is Valid BST: %s\n", is_bst_util(&root, LONG_MIN, LONG_MAX) ? "Yes" : "No");
    return 0;
}