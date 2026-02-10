#include <stdio.h>

int main() {
    int n;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter sorted elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    int j = 0;
    for (int i = 1; i < n; i++) {
        if (a[i] != a[j]) {
            j++;
            a[j] = a[i];
        }
    }

    printf("Array after removing duplicates: ");
    for (int i = 0; i <= j; i++)
        printf("%d ", a[i]);

    return 0;
}
