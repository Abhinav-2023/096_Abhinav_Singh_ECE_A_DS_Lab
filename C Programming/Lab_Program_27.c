/*
NAME :- ABHINAV SINGH
BRANCH :- ECE
SECTION :- A
ROLL NUMBER :- 2023ECE096
EXAM ROLL NUMBER :- 23294917096
ENROLLMENT NUMBER :- 23DOECBTEC000096
*/

/*
Implement 2 stacks using an array having moving partition for both choices
a) Stack 1 starts from start of array and Stack 2 starts from middle of array
b) Stack 1 starts from start of array and Stack 2 starts from the end of array
User will be prompted to make the choice
*/

#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

struct TwoStacks
{
    int arr[MAX_SIZE];
    int top1;
    int top2;
};

typedef struct TwoStacks TwoStacks;

TwoStacks *createTwoStacks()
{
    TwoStacks *twoStacks = (TwoStacks *)malloc(sizeof(TwoStacks));
    if (twoStacks == NULL)
    {
        printf("Memory allocation failed\n");
        exit(1);
    }
    twoStacks->top1 = -1;
    twoStacks->top2 = MAX_SIZE;
    return twoStacks;
}

void push1(TwoStacks *twoStacks, int value)
{
    if (twoStacks->top1 < twoStacks->top2 - 1)
    {
        twoStacks->arr[++twoStacks->top1] = value;
    }
    else
    {
        printf("Stack 1 overflow\n");
    }
}

void push2(TwoStacks *twoStacks, int value)
{
    if (twoStacks->top1 < twoStacks->top2 - 1)
    {
        twoStacks->arr[--twoStacks->top2] = value;
    }
    else
    {
        printf("Stack 2 overflow\n");
    }
}

int pop1(TwoStacks *twoStacks)
{
    if (twoStacks->top1 >= 0)
    {
        return twoStacks->arr[twoStacks->top1--];
    }
    else
    {
        printf("Stack 1 underflow\n");
        return -1;
    }
}

int pop2(TwoStacks *twoStacks)
{
    if (twoStacks->top2 < MAX_SIZE)
    {
        return twoStacks->arr[twoStacks->top2++];
    }
    else
    {
        printf("Stack 2 underflow\n");
        return -1;
    }
}

void display1(TwoStacks *twoStacks)
{
    if (twoStacks->top1 >= 0)
    {
        printf("Stack 1: ");
        for (int i = 0; i <= twoStacks->top1; i++)
        {
            printf("%d ", twoStacks->arr[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Stack 1 is empty\n");
    }
}

void display2(TwoStacks *twoStacks)
{
    if (twoStacks->top2 < MAX_SIZE)
    {
        printf("Stack 2: ");
        for (int i = MAX_SIZE - 1; i >= twoStacks->top2; i--)
        {
            printf("%d ", twoStacks->arr[i]);
        }
        printf("\n");
    }
    else
    {
        printf("Stack 2 is empty\n");
    }
}

int main()
{
    TwoStacks *twoStacks;
    int choice, value;

    twoStacks = createTwoStacks();

    printf("Choose the stack arrangement:\n");
    printf("1. Stack 1 starts from start of array and Stack 2 starts from middle of array\n");
    printf("2. Stack 1 starts from start of array and Stack 2 starts from the end of array\n");
    printf("Enter your choice: ");
    scanf("%d", &choice);

    switch (choice)
    {
    case 1:
        printf("You've chosen option 1\n");
        break;
    case 2:
        printf("You've chosen option 2\n");
        twoStacks->top2 = MAX_SIZE - 1;
        break;
    default:
        printf("Invalid choice. Exiting...\n");
        exit(1);
    }

    do
    {
        printf("\n1. Push to Stack 1\n");
        printf("2. Push to Stack 2\n");
        printf("3. Pop from Stack 1\n");
        printf("4. Pop from Stack 2\n");
        printf("5. Display Stack 1\n");
        printf("6. Display Stack 2\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to push to Stack 1: ");
            scanf("%d", &value);
            push1(twoStacks, value);
            break;
        case 2:
            printf("Enter value to push to Stack 2: ");
            scanf("%d", &value);
            push2(twoStacks, value);
            break;
        case 3:
            printf("Popped value from Stack 1: %d\n", pop1(twoStacks));
            break;
        case 4:
            printf("Popped value from Stack 2: %d\n", pop2(twoStacks));
            break;
        case 5:
            display1(twoStacks);
            break;
        case 6:
            display2(twoStacks);
            break;
        case 7:
            printf("Exiting...\n");
            break;
        default:
            printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 7);

    free(twoStacks);

    return 0;
}
