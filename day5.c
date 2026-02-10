#include <stdio.h>

int main() {
    int p, q;

    printf("Enter p: ");
    scanf("%d", &p);
    int a[p];
    printf("Log 1: ");
    for (int i = 0; i < p; i++) scanf("%d", &a[i]);

    printf("Enter q: ");
    scanf("%d", &q);
    int b[q];
    printf("Log 2: ");
    for (int i = 0; i < q; i++) scanf("%d", &b[i]);

    int i = 0, j = 0;
    printf("Merged log: ");
    while (i < p && j < q)
        printf("%d ", a[i] <= b[j] ? a[i++] : b[j++]);

    while (i < p) printf("%d ", a[i++]);
    while (j < q) printf("%d ", b[j++]);

    return 0;
}
