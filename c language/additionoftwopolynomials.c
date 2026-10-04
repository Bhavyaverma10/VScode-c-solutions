#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coeff;
    int power;
    struct Node *next;
};

struct Node* createNode(int coeff, int power)
{
    struct Node *newNode;
    newNode = (struct Node*)malloc(sizeof(struct Node));

    newNode->coeff = coeff;
    newNode->power = power;
    newNode->next = NULL;

    return newNode;
}

void insert(struct Node **head, int coeff, int power)
{
    struct Node *newNode = createNode(coeff, power);
    struct Node *temp;

    if(*head == NULL)
    {
        *head = newNode;
    }
    else
    {
        temp = *head;

        while(temp->next != NULL)
            temp = temp->next;

        temp->next = newNode;
    }
}

struct Node* add(struct Node *p1, struct Node *p2)
{
    struct Node *result = NULL;

    while(p1 != NULL && p2 != NULL)
    {
        if(p1->power == p2->power)
        {
            insert(&result, p1->coeff + p2->coeff, p1->power);
            p1 = p1->next;
            p2 = p2->next;
        }
        else if(p1->power > p2->power)
        {
            insert(&result, p1->coeff, p1->power);
            p1 = p1->next;
        }
        else
        {
            insert(&result, p2->coeff, p2->power);
            p2 = p2->next;
        }
    }

    while(p1 != NULL)
    {
        insert(&result, p1->coeff, p1->power);
        p1 = p1->next;
    }

    while(p2 != NULL)
    {
        insert(&result, p2->coeff, p2->power);
        p2 = p2->next;
    }

    return result;
}

void display(struct Node *head)
{
    while(head != NULL)
    {
        printf("%dx^%d", head->coeff, head->power);

        if(head->next != NULL)
            printf(" + ");

        head = head->next;
    }

    printf("\n");
}

int main()
{
    struct Node *p1 = NULL, *p2 = NULL, *sum;
    int n, i, coeff, power;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);

    printf("Enter coefficient and power:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d %d", &coeff, &power);
        insert(&p1, coeff, power);
    }

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n);

    printf("Enter coefficient and power:\n");
    for(i = 0; i < n; i++)
    {
        scanf("%d %d", &coeff, &power);
        insert(&p2, coeff, power);
    }

    sum = add(p1, p2);

    printf("First Polynomial: ");
    display(p1);

    printf("Second Polynomial: ");
    display(p2);

    printf("Addition: ");
    display(sum);

    return 0;
}