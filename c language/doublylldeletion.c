#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *prev;
    struct Node *next;
};

int main()
{
    struct Node *head = NULL, *newNode, *temp;
    int n, i, value, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create doubly linked list
    for(i = 0; i < n; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d", &value);

        newNode->data = value;
        newNode->prev = NULL;
        newNode->next = NULL;

        if(head == NULL)
        {
            head = newNode;
        }
        else
        {
            temp = head;

            while(temp->next != NULL)
            {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->prev = temp;
        }
    }

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    temp = head;

    // Move to the node to be deleted
    for(i = 1; i < pos; i++)
    {
        temp = temp->next;
    }

    // If deleting first node
    if(temp->prev == NULL)
    {
        head = temp->next;

        if(head != NULL)
        {
            head->prev = NULL;
        }
    }
    else
    {
        temp->prev->next = temp->next;

        if(temp->next != NULL)
        {
            temp->next->prev = temp->prev;
        }
    }

    free(temp);

    // Display list
    printf("Doubly Linked List after deletion: ");

    temp = head;

    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    return 0;
}