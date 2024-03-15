/*
NAME : ABHINAV SINGH
BRANCH : ECE-A
ENROLLMENT NUMBER : 23DOECBTEC000096
*/

/*
Design a C program to Check for Balanced Brackets in an Expression using Stack ADT.
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

typedef struct {
    char arr[MAX_SIZE];
    int top;
} Stack;

Stack* create_stack();
bool isEmpty(Stack* stack);
void push(Stack* stack, char value);
char pop(Stack* stack);
char peek(Stack* stack);
bool is_matching_pair(char opening, char closing);
bool are_brackets_balanced(char* expression);

Stack* create_stack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack));
    stack->top = -1;
    return stack;
}

bool isEmpty(Stack* stack) {
    return stack->top == -1;
}

void push(Stack* stack, char value) {
    if (stack->top == MAX_SIZE - 1) {
        printf("Stack overflow.\n");
        exit(EXIT_FAILURE);
    }
    stack->arr[++stack->top] = value;
}

char pop(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow.\n");
        exit(EXIT_FAILURE);
    }
    return stack->arr[stack->top--];
}

char peek(Stack* stack) {
    if (isEmpty(stack)) {
        return '\0';
    }
    return stack->arr[stack->top];
}

bool is_matching_pair(char opening, char closing) {
    if (opening == '(' && closing == ')') {
        return true;
    } else if (opening == '[' && closing == ']') {
        return true;
    } else if (opening == '{' && closing == '}') {
        return true;
    }
    return false;
}

bool are_brackets_balanced(char* expression) {
    Stack* stack = create_stack();
    int i = 0;

    while (expression[i] != '\0') {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            push(stack, expression[i]);
        } else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
            if (isEmpty(stack)) {
                return false;
            }
            char topChar = pop(stack);
            if (!is_matching_pair(topChar, expression[i])) {
                return false;
            }
        }
        i++;
    }

    if (!isEmpty(stack)) {
        return false;
    }

    free(stack);
    return true;
}

int main(void) {
    char expression[MAX_SIZE];

    printf("Enter an expression: ");
    scanf("%s", expression);

    if (are_brackets_balanced(expression)) {
        printf("The brackets in the expression are balanced.\n");
    } else {
        printf("The brackets in the expression are not balanced.\n");
    }
}
