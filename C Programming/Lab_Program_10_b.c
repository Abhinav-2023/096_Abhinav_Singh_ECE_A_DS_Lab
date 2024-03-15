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

typedef struct StackNode
{
    char data;
    struct StackNode *next;
} StackNode;

typedef struct
{
    StackNode *top;
} Stack;

Stack *createStack();
int isEmpty(Stack *stack);
void push(Stack *stack, char value);
char pop(Stack *stack);
char peek(Stack *stack);
int isOperator(char ch);
int precedence(char op);
void infixToPostfix(char *infix, char *postfix);
int isDigit(char ch);
int isAlpha(char ch);

Stack *createStack()
{
    Stack *stack = (Stack *)malloc(sizeof(Stack));
    stack->top = NULL;
    return stack;
}

int isEmpty(Stack *stack)
{
    return stack->top == NULL;
}

void push(Stack *stack, char value)
{
    StackNode *newNode = (StackNode *)malloc(sizeof(StackNode));
    newNode->data = value;
    newNode->next = stack->top;
    stack->top = newNode;
}

char pop(Stack *stack)
{
    if (isEmpty(stack))
    {
        printf("Stack underflow.\n");
        exit(EXIT_FAILURE);
    }
    StackNode *temp = stack->top;
    char poppedValue = temp->data;
    stack->top = temp->next;
    free(temp);
    return poppedValue;
}

char peek(Stack *stack)
{
    if (isEmpty(stack))
    {
        return '\0';
    }
    return stack->top->data;
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

void infixToPostfix(char *infix, char *postfix)
{
    Stack *stack = createStack();
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
    return (ch >= '0' && ch <= '9');
}

int isAlpha(char ch)
{
    return ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'));
}

int main(void)
{
    char infix[100], postfix[100];

    printf("Enter infix expression: ");
    fgets(infix, sizeof(infix), stdin);
    infix[strlen(infix) - 1] = '\0'; // Remove the newline character

    infixToPostfix(infix, postfix);

    printf("Postfix expression: %s\n", postfix);

}
