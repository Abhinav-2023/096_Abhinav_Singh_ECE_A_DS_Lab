#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
} *top = NULL;

void push(struct Node *t, int x)
{
    t = (struct Node *)malloc(sizeof(struct Node));
    if (t == NULL)
    {
        printf("Stack is full.\n");
    }
    else
    {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int pop(struct Node *t)
{
    int x = -1;
    if (top == NULL)
    {
        printf("Stack is empty.\n");
    }
    else
    {
        t = top;
        top = top->next;
        x = t->data;
        free(t);
    }
    return x;
}

void display(struct Node *p)
{
    p = top;
    while (p != NULL)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

int peek(struct Node *top)
{
    if (top == NULL)
    {
        printf("Stack is empty.\n");
    }
    return top->data;
}

int main(void)
{
    int choice, t, p, x;

    do
    {
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("=> Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter element to push: ");
            scanf("%d", &x);
            push(&t, x);
            break;
        case 2:
            printf("Popped element: %d\n", pop(&t));
            break;
        case 3:
            printf("Top element: %d\n", peek(top));
            break;
        case 4:
            display(p);
            break;
        case 5:
            printf("Exiting ...\n");
            break;
        default:
            printf("Invalid choice.");
        }
    } while (choice != 5);
}