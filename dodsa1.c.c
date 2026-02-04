#include <stdio.h>

int main()
{
    int n, pos, x;

    printf("Enter size of array\n");
    scanf("%d", &n);

    int a[n+1];

    printf("Enter array elements\n");
    for(int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter position\n");
    scanf("%d", &pos);

    printf("Enter element to insert\n");
    scanf("%d", &x);

    for(int i = n; i >= pos; i--)
    {
        a[i] = a[i-1];
    }

    a[pos-1] = x;

    printf("Updated array\n");
    for(int i = 0; i < n+1; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}
