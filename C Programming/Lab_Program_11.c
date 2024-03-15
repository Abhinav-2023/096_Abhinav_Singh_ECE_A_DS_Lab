/*
NAME : ABHINAV SINGH
BRANCH : ECE-A
ENROLLMENT NUMBER : 23DOECBTEC000096
*/

/*
Design a C Program to Evaluate POSTFIX Expression Using Stack ADT.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 100

typedef struct {
    int arr[MAX_SIZE];
    int top;
} Stack;

Stack* create_stack();
int isEmpty(Stack* stack);
void push(Stack* stack, int value);
int pop(Stack* stack);
int isDigit(char ch);
int evaluate_post_fix(char* postfix);

Stack* create_stack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

int isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, int value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow.\n");
        exit(EXIT_FAILURE);
    }
    stack->arr[++stack->top] = value;
}

int pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow.\n");
        exit(EXIT_FAILURE);
    }
    return stack->arr[stack->top--];
}

int isDigit(char ch) {
    return ch >= '0' && ch <= '9';
}

int evaluate_post_fix(char* postfix) {
    Stack* stack = create_stack();
    int i = 0, operand1, operand2, result;

    while (postfix[i] != '\0') {
        if (isDigit(postfix[i])) {
            push(stack, postfix[i] - '0');
        } else {
            operand2 = pop(stack);
            operand1 = pop(stack);
            switch (postfix[i]) {
                case '+':
                    result = operand1 + operand2;
                    break;
                case '-':
                    result = operand1 - operand2;
                    break;
                case '*':
                    result = operand1 * operand2;
                    break;
                case '/':
                    result = operand1 / operand2;
                    break;
                default:
                    printf("Invalid postfix expression.\n");
                    exit(EXIT_FAILURE);
            }
            push(stack, result);
        }
        i++;
    }

    result = pop(stack);
    free(stack);
    return result;
}

int main(void) {
    char postfix[MAX_SIZE];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    int result = evaluate_post_fix(postfix);
    printf("Result: %d\n", result);

}
