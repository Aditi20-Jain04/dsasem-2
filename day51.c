#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node *left, *right;
};

struct Node* insert(struct Node* root, int x) {
    if (!root) {
        root = (struct Node*)malloc(sizeof(struct Node));
        root->data = x;
        root->left = root->right = NULL;
    } else if (x < root->data)
        root->left = insert(root->left, x);
    else
        root->right = insert(root->right, x);
    return root;
}

struct Node* LCA(struct Node* root, int a, int b) {
    if (a < root->data && b < root->data)
        return LCA(root->left, a, b);
    if (a > root->data && b > root->data)
        return LCA(root->right, a, b);
    return root;
}

int main() {
    int n, x, a, b;
    scanf("%d", &n);

    struct Node* root = NULL;
    while (n--) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    scanf("%d %d", &a, &b);
    printf("%d", LCA(root, a, b)->data);
    return 0;
}