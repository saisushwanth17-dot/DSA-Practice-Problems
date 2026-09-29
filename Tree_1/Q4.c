#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node *left, *right; };

int search(int arr[], int strt, int end, int val) {
    for (int i = strt; i <= end; i++) if (arr[i] == val) return i;
    return -1;
}

struct Node* build_tree(int in[], int post[], int inStrt, int inEnd, int* postIdx) {
    if (inStrt > inEnd) return NULL;
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = post[*postIdx]; (*postIdx)--;
    node->left = node->right = NULL;
    if (inStrt == inEnd) return node;
    int inIndex = search(in, inStrt, inEnd, node->data);
    node->right = build_tree(in, post, inIndex + 1, inEnd, postIdx);
    node->left = build_tree(in, post, inStrt, inIndex - 1, postIdx);
    return node;
}

void preorder(struct Node* root) {
    if (root) { printf("%d ", root->data); preorder(root->left); preorder(root->right); }
}

int main() {
    int in[] = {4, 2, 5, 1, 3}, post[] = {4, 5, 2, 3, 1};
    int postIndex = 4;
    struct Node* root = build_tree(in, post, 0, 4, &postIndex);
    printf("Preorder Traversal: ");
    preorder(root);
    printf("\n");
    return 0;
}