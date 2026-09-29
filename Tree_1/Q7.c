#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node *left, *right; };

int diameter(struct Node* root, int* height) {
    int lh = 0, rh = 0, ldia = 0, rdia = 0;
    if (root == NULL) { *height = 0; return 0; }
    ldia = diameter(root->left, &lh);
    rdia = diameter(root->right, &rh);
    *height = (lh > rh ? lh : rh) + 1;
    int max_sub = (ldia > rdia ? ldia : rdia);
    return (lh + rh + 1 > max_sub ? lh + rh + 1 : max_sub);
}

int main() {
    struct Node root = {1, NULL, NULL}, n2 = {2, NULL, NULL}, n3 = {3, NULL, NULL};
    struct Node n4 = {4, NULL, NULL}, n5 = {5, NULL, NULL};
    root.left = &n2; root.right = &n3; n2.left = &n4; n2.right = &n5;
    int h = 0;
    printf("Diameter of Tree: %d\n", diameter(&root, &h));
    return 0;
}