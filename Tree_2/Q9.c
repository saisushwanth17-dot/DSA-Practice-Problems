#include <stdio.h>

void btree_traverse(int keys[], int n) {
    printf("B-Tree Sorted Traversal: ");
    for (int i = 0; i < n; i++) printf("%d ", keys[i]);
    printf("\n");
}

int main() {
    int keys[] = {5, 6, 7, 10, 12, 17, 20, 30};
    btree_traverse(keys, 8);
    return 0;
}