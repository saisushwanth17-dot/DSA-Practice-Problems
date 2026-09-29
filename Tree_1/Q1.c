#include <stdio.h>
#include <stdlib.h>

struct Node {
    int key;
    struct Node *left, *right;
};

struct Node* insert(struct Node* node, int key) {
    if (node == NULL) {
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->key = key; temp->left = temp->right = NULL;
        return temp;
    }
    if (key < node->key) node->left = insert(node->left, key);
    else node->right = insert(node->right, key);
    return node;
}

void inorder(struct Node* root) {
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->key);
        inorder(root->right);
    }
}

int main() {
    struct Node* root = NULL;
    int keys[] = {200, 120, 80, 160, 280, 240, 320};
    for (int i = 0; i < 7; i++) root = insert(root, keys[i]);
    printf("Inorder Traversal: ");
    inorder(root);
    printf("\n");
    return 0;
}