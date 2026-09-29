#include <stdio.h>
#include <stdlib.h>

struct Node { int data; struct Node *left, *right; };

struct Node* sorted_arr_to_bst(int arr[], int start, int end) {
    if (start > end) return NULL;
    int mid = (start + end) / 2;
    struct Node* root = (struct Node*)malloc(sizeof(struct Node));
    root->data = arr[mid];
    root->left = sorted_arr_to_bst(arr, start, mid - 1);
    root->right = sorted_arr_to_bst(arr, mid + 1, end);
    return root;
}

void preorder(struct Node* root) {
    if (root) { printf("%d ", root->data); preorder(root->left); preorder(root->right); }
}

int main() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    struct Node* root = sorted_arr_to_bst(arr, 0, 6);
    printf("Preorder of Balanced BST: ");
    preorder(root);
    printf("\n");
    return 0;
}