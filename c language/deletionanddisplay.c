#include <stdio.h>

int main()
{
    int a[100], n, i, pos;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements of array:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    // Display
    printf("Array before deletion:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    // Deletion
    printf("\nEnter position to delete: ");
    scanf("%d", &pos);

    for(i = pos - 1; i < n - 1; i++)
    {
        a[i] = a[i + 1];
    }

    n--;

    // Display after deletion
    printf("Array after deletion:\n");
    for(i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }

    return 0;
}