#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

int main()
{
    struct Node *head = NULL, *newNode, *temp;
    int n, i, value;

    printf("Enter number of nodes: ");
    scanf("%d", &n);

    // Create initial circular linked list
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

    // Insert a new node at the end
    newNode = (struct Node*)malloc(sizeof(struct Node));

    printf("Enter value to insert: ");
    scanf("%d", &value);

    newNode->data = value;

    temp = head;

    while(temp->next != head)
    {
        temp = temp->next;
    }

    temp->next = newNode;
    newNode->next = head;

    // Display circular linked list
    printf("Circular Linked List: ");

    temp = head;

    do
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    while(temp != head);

    return 0;
}