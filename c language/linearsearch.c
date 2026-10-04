#include <stdio.h>

int main()
{
    int a[100], n, search, i;
    int found = 0;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements of array:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &search);

    for(i = 0; i < n; i++)
    {
        if(a[i] == search)
        {
            printf("Element found at index %d", i);
            found = 1;
            break;
        }
    }

    if(found == 0)
    {
        printf("Element not found");
    }

    return 0;
}