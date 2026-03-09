#include <stdio.h>

int main() {
    int n;
    scanf("%d", &n);

    int q[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &q[i]);
    }

    int m;
    scanf("%d", &m);

    int front = m % n;

    for (int i = 0; i < n; i++) {
        printf("%d ", q[(front + i) % n]);
    }

    return 0;
}