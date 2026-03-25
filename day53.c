#include <stdio.h>
#include <stdlib.h>

#define MAX 100

// Tree node
struct Node {
    int data;
    struct Node *left, *right;
};

// Queue for BFS
struct QNode {
    struct Node* node;
    int hd;
};

struct Node* createNode(int data) {
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = data;
    n->left = n->right = NULL;
    return n;
}

// Build tree from level-order array
struct Node* buildTree(int arr[], int n) {
    if (n == 0 || arr[0] == -1) return NULL;

    struct Node* root = createNode(arr[0]);
    struct Node* queue[MAX];
    int front = 0, rear = 0;
    queue[rear++] = root;

    int i = 1;
    while (i < n) {
        struct Node* curr = queue[front++];

        if (arr[i] != -1) {
            curr->left = createNode(arr[i]);
            queue[rear++] = curr->left;
        }
        i++;

        if (i < n && arr[i] != -1) {
            curr->right = createNode(arr[i]);
            queue[rear++] = curr->right;
        }
        i++;
    }
    return root;
}

void verticalOrder(struct Node* root) {
    if (!root) return;

    int minHD = 0, maxHD = 0;
    int vertical[MAX][MAX], count[MAX] = {0};

    struct QNode q[MAX];
    int front = 0, rear = 0;

    q[rear++] = (struct QNode){root, 0};

    while (front < rear) {
        struct QNode temp = q[front++];
        struct Node* curr = temp.node;
        int hd = temp.hd;

        vertical[hd + MAX / 2][count[hd + MAX / 2]++] = curr->data;

        if (hd < minHD) minHD = hd;
        if (hd > maxHD) maxHD = hd;

        if (curr->left)
            q[rear++] = (struct QNode){curr->left, hd - 1};
        if (curr->right)
            q[rear++] = (struct QNode){curr->right, hd + 1};
    }

    // Print result
    for (int i = minHD; i <= maxHD; i++) {
        for (int j = 0; j < count[i + MAX / 2]; j++) {
            printf("%d ", vertical[i + MAX / 2][j]);
        }
        printf("\n");
    }
}

int main() {
    int n;
    scanf("%d", &n);

    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    struct Node* root = buildTree(arr, n);
    verticalOrder(root);

    return 0;
}