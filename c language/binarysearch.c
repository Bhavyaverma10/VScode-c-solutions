#include <stdio.h>

int main()
{
    int a[100], n, search;
    int low, high, mid;
    int i, found = 0;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements in ascending order:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Enter element to search: ");
    scanf("%d", &search);

    low = 0;
    high = n - 1;

    while(low <= high)
    {
        mid = (low + high) / 2;

        if(a[mid] == search)
        {
            printf("Element found at index %d", mid);
            found = 1;
            break;
        }
        else if(search < a[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if(found == 0)
    {
        printf("Element not found");
    }

    return 0;
}