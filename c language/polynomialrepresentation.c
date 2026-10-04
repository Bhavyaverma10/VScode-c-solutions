#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int power;
    struct Node *next;
};

int main()
{
    struct Node *head = NULL, *newNode, *temp;
    int n, i;

    printf("Enter number of terms: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        newNode = (struct Node*)malloc(sizeof(struct Node));

        printf("Enter coefficient and power: ");
        scanf("%d %d", &newNode->coeff, &newNode->power);

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
        }
    }

    printf("Polynomial: ");

    temp = head;

    while(temp != NULL)
    {
        printf("%dx^%d", temp->coeff, temp->power);

        if(temp->next != NULL)
            printf(" + ");

        temp = temp->next;
    }

    return 0;
}