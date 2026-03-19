#include <stdio.h>
#include <stdlib.h>

struct Node {
    int left, right;
};

int height(struct Node* tree, int root) {
    if (root == -1) return -1;
    int l = height(tree, tree[root].left);
    int r = height(tree, tree[root].right);
    return (l > r ? l : r) + 1;
}

int main() {
    int n;
    scanf("%d", &n);
    
    if (n == 0) {
        printf("-1\n");
        return 0;
    }
    
    struct Node* tree = malloc(n * sizeof(struct Node));
    int data; // Read but ignore node values
    for (int i = 0; i < n; i++)
        scanf("%d %d %d", &data, &tree[i].left, &tree[i].right);
    
    printf("%d\n", height(tree, 0));
    free(tree);
    return 0;
}