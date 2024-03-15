/*
NAME : ABHINAV SINGH
BRANCH : ECE-A
ENROLLMENT NUMBER : 23DOECBTEC000096
*/

/*
Design a program to implement Stack ADT using arrays.
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int *create_stack()
{
    int *stack = (int *)malloc(MAX_SIZE * sizeof(int));
    return stack;
}

int isEmpty(int *stack, int top)
{
    return top == -1;
}

void push(int *stack, int *top, int value)
{
    if (*top == MAX_SIZE - 1)
    {
        printf("Stack overflow.\n");
        return;
    }
    stack[++(*top)] = value;
}

int pop(int *stack, int *top)
{
    if (isEmpty(stack, *top))
    {
        printf("Stack underflow.\n");
        return -1;
    }
    return stack[(*top)--];
}

int peek(int *stack, int top)
{
    if (isEmpty(stack, top))
    {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack[top];
}

int main(void)
{
    int *stack = create_stack();
    int top = -1;

    push(stack, &top, 10);
    push(stack, &top, 20);
    push(stack, &top, 30);

    printf("Top element: %d\n", peek(stack, top));

    printf("Popping elements:\n");
    while (!isEmpty(stack, top))
    {
        printf("%d\n", pop(stack, &top));
    }

    if (isEmpty(stack, top))
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack is not empty.\n");
    }

    free(stack);
}
