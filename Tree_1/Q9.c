#include <stdio.h>
#include <stdbool.h>

struct Node { int data; struct Node *left, *right; };

bool is_identical(struct Node* r1, struct Node* r2) {
    if (r1 == NULL && r2 == NULL) return true;
    if (r1 != NULL && r2 != NULL)
        return (r1->data == r2->data) && is_identical(r1->left, r2->left) && is_identical(r1->right, r2->right);
    return false;
}

int main() {
    struct Node t1 = {1, NULL, NULL}, t2 = {1, NULL, NULL};
    struct Node l1 = {2, NULL, NULL}, l2 = {2, NULL, NULL};
    t1.left = &l1; t2.left = &l2;
    printf("Comparison Result: %s\n", is_identical(&t1, &t2) ? "Trees are Identical" : "Not Identical");
    return 0;
}