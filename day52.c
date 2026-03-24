#include <stdio.h>
#include <stdlib.h>

// Structure of tree node
struct Node {
    int data;
    struct Node* left;
    struct Node* right;
};

// Create new node
struct Node* newNode(int val) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = val;
    node->left = node->right = NULL;
    return node;
}

// Build tree using level order input
struct Node* buildTree() {
    int val;
    scanf("%d", &val);

    if (val == -1)
        return NULL;

    struct Node* root = newNode(val);

    struct Node* queue[100];
    int front = 0, rear = 0;
    queue[rear++] = root;

    while (front < rear) {
        struct Node* curr = queue[front++];

        int leftVal, rightVal;
        scanf("%d %d", &leftVal, &rightVal);

        if (leftVal != -1) {
            curr->left = newNode(leftVal);
            queue[rear++] = curr->left;
        }

        if (rightVal != -1) {
            curr->right = newNode(rightVal);
            queue[rear++] = curr->right;
        }
    }
    return root;
}

// Function to find LCA
struct Node* LCA(struct Node* root, int n1, int n2) {
    if (root == NULL)
        return NULL;

    if (root->data == n1 || root->data == n2)
        return root;

    struct Node* left = LCA(root->left, n1, n2);
    struct Node* right = LCA(root->right, n1, n2);

    if (left && right)
        return root;

    return (left != NULL) ? left : right;
}

// Main function
int main() {
    int N;
    scanf("%d", &N);   // Number of nodes (not strictly required)

    struct Node* root = buildTree();

    int n1, n2;
    scanf("%d %d", &n1, &n2);

    struct Node* ans = LCA(root, n1, n2);

    if (ans != NULL)
        printf("%d", ans->data);
    else
        printf("-1");

    return 0;
}