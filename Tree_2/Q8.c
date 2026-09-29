#include <stdio.h>
#include <stdlib.h>

struct MinHeapNode { char data; unsigned freq; struct MinHeapNode *left, *right; };

void printCodes(struct MinHeapNode* root, int arr[], int top) {
    if (root->left) { arr[top] = 0; printCodes(root->left, arr, top + 1); }
    if (root->right) { arr[top] = 1; printCodes(root->right, arr, top + 1); }
    if (!root->left && !root->right) {
        printf("%c: ", root->data);
        for (int i = 0; i < top; i++) printf("%d", arr[i]);
        printf("\n");
    }
}

int main() {
    struct MinHeapNode f = {'f', 45, NULL, NULL}, c = {'c', 12, NULL, NULL}, d = {'d', 13, NULL, NULL};
    struct MinHeapNode cd = {'$', 25, &c, &d}, root = {'$', 70, &f, &cd};
    int arr[10];
    printf("Huffman Codes:\n");
    printCodes(&root, arr, 0);
    return 0;
}