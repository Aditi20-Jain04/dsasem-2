#include <stdio.h>

int main() {
    int n, k, found = 0, index = -1, comparisons = 0;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    int a[n];
    printf("Enter the elements: ");
    for (int i = 0; i < n; i++)
        scanf("%d", &a[i]);

    printf("Enter key to search: ");
    scanf("%d", &k);

    for (int i = 0; i < n; i++) {
        comparisons++;
        if (a[i] == k) {
            found = 1;
            index = i;
            break;
        }
    }

    if (found)
        printf("Found at index %d\n", index);
    else
        printf("Not Found\n");

    printf("Comparisons = %d", comparisons);

    return 0;
}
