#include <stdio.h>

int main() {
    int n, pos;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    for (int i = pos - 1; i < n - 1; i++)
        a[i] = a[i + 1];

    printf("Updated array: ");
    for (int i = 0; i < n - 1; i++)
        printf("%d ", a[i]);

    return 0;
}
