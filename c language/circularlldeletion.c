#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *head = NULL, *newNode, *temp, *prev;
    int n, i, value, pos;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create circular linked list
    for(i = 0; i < n; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter data: ");
        scanf("%d", &value);

        newNode->data = value;

        if(head == NULL)
        {
            head = newNode;
            newNode->next = head;
        }
        else
        {
            temp = head;

            while(temp->next != head)
            {
                temp = temp->next;
            }

            temp->next = newNode;
            newNode->next = head;
        }
    }

    printf("Enter position to delete: ");
    scanf("%d", &pos);

    // Delete first node
    if(pos == 1)
    {
        temp = head;

        while(temp->next != head)
        {
            temp = temp->next;
        }

        if(head->next == head)
        {
            head = NULL;
        }
        else
        {
            temp->next = head->next;
            head = head->next;
        }

        free(temp);
    }
    else
    {
        temp = head;

        for(i = 1; i < pos - 1; i++)
        {
            temp = temp->next;
        }

        prev = temp;
        temp = temp->next;

        prev->next = temp->next;

        free(temp);
    }

    // Display list
    if(head == NULL)
    {
        printf("List is empty");
    }
    else
    {
        printf("Circular Linked List after deletion: ");

        temp = head;

        do
        {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        while(temp != head);
    }

    return 0;
}