#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node *left, *right; };

struct Node* lca(struct Node* root, int n1, int n2) {
    if (root == NULL) return NULL;
    if (root->data > n1 && root->data > n2) return lca(root->left, n1, n2);
    if (root->data < n1 && root->data < n2) return lca(root->right, n1, n2);
    return root;
}

int main() {
    struct Node n10 = {10, NULL, NULL}, n14 = {14, NULL, NULL};
    struct Node n12 = {12, &n10, &n14}, n4 = {4, NULL, NULL}, n22 = {22, NULL, NULL};
    struct Node n8 = {8, &n4, &n12}, root = {20, &n8, &n22};
    printf("LCA of 10 and 14: %d\n", lca(&root, 10, 14)->data);
    return 0;
}