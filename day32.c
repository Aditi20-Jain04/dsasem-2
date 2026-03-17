#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int stack[n];
    int top = -1;

    // Push n elements
    for (int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        stack[++top] = x;
    }

    int m;
    scanf("%d", &m);

    // Pop m elements
    for (int i = 0; i < m; i++) {
        if (top != -1)
            top--;
    }

    // Display remaining stack
    for (int i = top; i >= 0; i--) {
        printf("%d ", stack[i]);
    }

    return 0;
}