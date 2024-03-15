/*
NAME : ABHINAV SINGH
BRANCH : ECE-A
ENROLLMENT NUMBER : 23DOECBTEC000096
*/

/*
Design a program to implement Stack ADT using structures
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

typedef struct StackNode
{
    int data;
    struct StackNode *next;
} StackNode;

typedef struct
{
    StackNode *top;
} Stack;

Stack *create_stack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

int isEmpty(Stack *stack)
{
    return stack->top == NULL;
}

void push(Stack *stack, int value)
{
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

int pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow.\n");
        return -1;
    }
    StackNode *temp = stack->top;
    int poppedValue = temp->data;
    stack->top = temp->next;
    free(temp);
    return poppedValue;
}

int peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack is empty.\n");
        return -1;
    }
    return stack->top->data;
}

int main(void)
{
    Stack *stack = create_stack();

    push(stack, 10);
    push(stack, 20);
    push(stack, 30);

    printf("Top element: %d\n", peek(stack));

    printf("Popping elements:\n");
    while (!isEmpty(stack))
    {
        printf("%d\n", pop(stack));
    }

    if (isEmpty(stack))
    {
        printf("Stack is empty.\n");
    }
    else
    {
        printf("Stack is not empty.\n");
    }

    free(stack);
}