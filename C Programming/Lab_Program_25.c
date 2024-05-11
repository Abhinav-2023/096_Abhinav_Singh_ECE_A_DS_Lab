/*
NAME :- ABHINAV SINGH
BRANCH :- ECE
SECTION :- A
ROLL NUMBER :- 2023ECE096
EXAM ROLL NUMBER :- 23294917096
ENROLLMENT NUMBER :- 23DOECBTEC000096
*/

/*
Write a program in C to implement stack ADT to perform polynomial addition using stacks.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int coefficient;
    int exponent;
    struct Node *next;
};

typedef struct Node Node;

Node *createNode(int coefficient, int exponent)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->coefficient = coefficient;
    newNode->exponent = exponent;
    newNode->next = NULL;
    return newNode;
}

void push(Node **top, int coefficient, int exponent)
{
    Node *newNode = createNode(coefficient, exponent);
    newNode->next = *top;
    *top = newNode;
}

void pop(Node **top)
{
    if (*top == NULL)
    {
        printf("Stack underflow\n");
        exit(1);
    }
    Node *temp = *top;
    *top = (*top)->next;
    free(temp);
}

int isEmpty(Node *top)
{
    return top == NULL;
}

void display(Node *top)
{
    if (top == NULL)
    {
        printf("Stack is empty\n");
        return;
    }
    Node *current = top;
    while (current != NULL)
    {
        printf("%dx^%d ", current->coefficient, current->exponent);
        if (current->next != NULL)
            printf("+ ");
        current = current->next;
    }
    printf("\n");
}

void addPolynomials(Node **result, Node *poly1, Node *poly2)
{
    while (poly1 != NULL && poly2 != NULL)
    {
        if (poly1->exponent > poly2->exponent)
        {
            push(result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        }
        else if (poly1->exponent < poly2->exponent)
        {
            push(result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        }
        else
        {
            int sum = poly1->coefficient + poly2->coefficient;
            if (sum != 0)
                push(result, sum, poly1->exponent);
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL)
    {
        push(result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }

    while (poly2 != NULL)
    {
        push(result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }
}

void clearStack(Node **top)
{
    while (!isEmpty(*top))
        pop(top);
}

int main()
{
    Node *poly1 = NULL;
    Node *poly2 = NULL;
    Node *result = NULL;
    int choice;
    int coefficient, exponent;

    do
    {
        printf("\nPolynomial Addition using Stack\n");
        printf("1. Add polynomial 1\n");
        printf("2. Add polynomial 2\n");
        printf("3. Add polynomials\n");
        printf("4. Display result\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter coefficient and exponent for polynomial 1: ");
            scanf("%d %d", &coefficient, &exponent);
            push(&poly1, coefficient, exponent);
            break;
        case 2:
            printf("Enter coefficient and exponent for polynomial 2: ");
            scanf("%d %d", &coefficient, &exponent);
            push(&poly2, coefficient, exponent);
            break;
        case 3:
            if (poly1 == NULL || poly2 == NULL)
            {
                printf("Both polynomials should be added first.\n");
            }
            else
            {
                addPolynomials(&result, poly1, poly2);
                printf("Polynomials added successfully.\n");
            }
            break;
        case 4:
            printf("Resultant Polynomial: ");
            display(result);
            break;
        case 5:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);

    clearStack(&poly1);
    clearStack(&poly2);
    clearStack(&result);

    return 0;
}
