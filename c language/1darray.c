#include <stdio.h>

int main()
{
    int a[100], n, i, choice, pos, value;

    printf("Enter number of elements: ");
    scanf("%d", &n);

    printf("Enter array elements:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    while(1)
    {
        printf("\n\n--- MENU ---\n");
        printf("1. Traversal\n");
        printf("2. Insertion\n");
        printf("3. Deletion\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                // Traversal
                printf("Array elements are: ");
                for(i = 0; i < n; i++)
                {
                    printf("%d ", a[i]);
                }
                break;

            case 2:
                // Insertion
                printf("Enter position for insertion: ");
                scanf("%d", &pos);

                printf("Enter value: ");
                scanf("%d", &value);

                for(i = n; i >= pos; i--)
                {
                    a[i] = a[i - 1];
                }

                a[pos - 1] = value;
                n++;

                printf("Element inserted successfully.\n");

                printf("Array after insertion: ");
                for(i = 0; i < n; i++)
                {
                    printf("%d ", a[i]);
                }
                break;

            case 3:
                // Deletion
                printf("Enter position for deletion: ");
                scanf("%d", &pos);

                for(i = pos - 1; i < n - 1; i++)
                {
                    a[i] = a[i + 1];
                }

                n--;

                printf("Element deleted successfully.\n");

                printf("Array after deletion: ");
                for(i = 0; i < n; i++)
                {
                    printf("%d ", a[i]);
                }
                break;

            case 4:
                return 0;

            default:
                printf("Invalid choice!");
        }
    }

    return 0;
}