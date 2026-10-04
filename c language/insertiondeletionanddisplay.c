#include <stdio.h>

int main()
{
    int a[100], n, i, pos, value, choice;

    printf("Enter size of array: ");
    scanf("%d", &n);

    printf("Enter elements of array:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }

    do
    {
        printf("\n--- MENU ---\n");
        printf("1. Insertion\n");
        printf("2. Deletion\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                // Insertion
                printf("Enter position: ");
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
                break;

            case 2:
                // Deletion
                printf("Enter position to delete: ");
                scanf("%d", &pos);

                for(i = pos - 1; i < n - 1; i++)
                {
                    a[i] = a[i + 1];
                }

                n--;

                printf("Element deleted successfully.\n");
                break;

            case 3:
                // Display
                printf("Array elements are:\n");

                for(i = 0; i < n; i++)
                {
                    printf("%d ", a[i]);
                }

                printf("\n");
                break;

            case 4:
                printf("Program ended.\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while(choice != 4);

    return 0;
}