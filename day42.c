#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int queue[n], stack[n];
    int front = 0, rear = n - 1, top = -1;

    for (int i = 0; i < n; i++) {
        scanf("%d", &queue[i]);
    }

    // Push all elements into stack
    for (int i = front; i <= rear; i++) {
        stack[++top] = queue[i];
    }

    // Pop from stack back to queue
    for (int i = 0; i < n; i++) {
        queue[i] = stack[top--];
    }

    // Print reversed queue
    for (int i = 0; i < n; i++) {
        printf("%d ", queue[i]);
    }

    return 0;
}