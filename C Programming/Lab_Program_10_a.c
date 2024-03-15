/*
NAME : ABHINAV SINGH
BRANCH : ECE-A
ENROLLMENT NUMBER : 23DOECBTEC000096
*/

/*
Design a program to convert infix notation to postfix notation using
a)array based Stack
b)struct based stack
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct
{
    char arr[MAX_SIZE];
    int top;
} Stack;

Stack *create_stack();
int isEmpty(Stack *stack);
void push(Stack *stack, char value);
char pop(Stack *stack);
char peek(Stack *stack);
int isOperator(char ch);
int precedence(char op);
void infix_to_postfix(char *infix, char *postfix);
int isDigit(char ch);
int isAlpha(char ch);

Stack *create_stack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

int isEmpty(Stack *stack)
{
    return stack->top == -1;
}

void push(Stack *stack, char value)
{
    if (stack->top == MAX_SIZE - 1)
    {
        printf("Stack overflow.\n");
        exit(EXIT_FAILURE);
    }
    stack->arr[++stack->top] = value;
}

char pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow.\n");
        exit(EXIT_FAILURE);
    }
    return stack->arr[stack->top--];
}

char peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        return '\0';
    }
    return stack->arr[stack->top];
}

int isOperator(char ch)
{
    char operators[] = "+-*/";
    return strchr(operators, ch) != NULL;
}

int precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}

void infix_to_postfix(char *infix, char *postfix)
{
    Stack *stack = create_stack();
    int i = 0, j = 0;
    char ch;

    while ((ch = infix[i++]) != '\0')
    {
        if (isDigit(ch) || isAlpha(ch))
        {
            postfix[j++] = ch;
        }
        else if (isOperator(ch))
        {
            while (!isEmpty(stack) && precedence(ch) <= precedence(peek(stack)))
            {
                postfix[j++] = pop(stack);
            }
            push(stack, ch);
        }
        else if (ch == '(')
        {
            push(stack, ch);
        }
        else if (ch == ')')
        {
            while (peek(stack) != '(')
            {
                postfix[j++] = pop(stack);
            }
            pop(stack); // Discard the '('
        }
    }

    while (!isEmpty(stack))
    {
        postfix[j++] = pop(stack);
    }

    postfix[j] = '\0';
    free(stack);
}

int isDigit(char ch)
{
    return ch >= '0' && ch <= '9';
}

int isAlpha(char ch)
{
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z');
}

int main(void)
{
    char infix[MAX_SIZE], postfix[MAX_SIZE];

    printf("Enter infix expression: ");
    scanf("%s", infix);

    infix_to_postfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

}