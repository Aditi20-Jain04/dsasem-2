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

int search(struct Node* root, int key) {
    if (!root) return 0;
    if (root->data == key) return 1;
    return key < root->data ? search(root->left, key)
                            : search(root->right, key);
}

int main() {
    int n, x, key;
    scanf("%d", &n);

    struct Node* root = NULL;
    while (n--) {
        scanf("%d", &x);
        root = insert(root, x);
    }

    scanf("%d", &key);
    printf(search(root, key) ? "Found" : "Not Found");
    return 0;
}