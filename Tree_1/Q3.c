#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

int max_depth(struct Node* node) {
    if (node == NULL) return 0;
    int lDepth = max_depth(node->left);
    int rDepth = max_depth(node->right);
    return (lDepth > rDepth ? lDepth : rDepth) + 1;
}

int main() {
    struct Node root = {1, NULL, NULL};
    struct Node n2 = {2, NULL, NULL}, n3 = {3, NULL, NULL}, n4 = {4, NULL, NULL};
    root.left = &n2; root.right = &n3; n2.left = &n4;
    printf("Height of Tree: %d\n", max_depth(&root));
    return 0;
}