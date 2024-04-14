/*
NAME :- ABHINAV SINGH
BRANCH :- ECE
SECTION :- A
ROLL NUMBER :- 2023ECE096
EXAM ROLL NUMBER :- 23294917096
ENROLLMENT NUMBER :- 23DOECBTEC000096
*/

/*
Implement Queue ADT and perform its operations in C.
*/

#include <stdio.h>
#include <stdlib.h>

int front = -1;
int rear = -1;
int *arr = NULL;

int isFull(int size, int rear)
{
    return (rear == size - 1);
}

int isEmpty(int front, int rear)
{
    return (front == rear);
}

void displayQueue(int *arr, int front, int rear)
{
    if (isEmpty(front, rear))
    {
        printf("Empty\n");
        return;
    }
    for (int i = front + 1; i <= rear; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void enqueue(int *arr, int *rear, int size, int val)
{
    if (isFull(size, *rear))
        printf("=> Queue Overflow\n");
    
    else
    {
        arr[++(*rear)] = val;
        printf("=> Enqueued element: %d\n", val);
        printf("=> Current Queue: ");
        displayQueue(arr, front, *rear);
    }
}

int dequeue(int *arr, int *front, int rear)
{
    int val = -1;
    if (isEmpty(*front, rear))
    {
        printf("=> Queue Underflow\n");
    }
    else
    {
        val = arr[++(*front)];
        printf("=> Dequeued element: %d\n", val);
    }
    return val;
}

int peek(int *arr, int front, int rear)
{
    if (isEmpty(front, rear))
    {
        printf("=> Queue is empty\n");
        return -1;
    }
    else
    {
        return arr[front + 1];
    }
}

void displayMenu()
{
    printf("1. Enqueue\n");
    printf("2. Dequeue\n");
    printf("3. Peek\n");
    printf("4. Check if queue is full\n");
    printf("5. Check if queue is empty\n");
    printf("6. Exit\n");
}

int main(void)
{
    int size;
    printf("=> Enter the size of the queue: ");
    scanf("%d", &size);

    arr = (int *)malloc(size * sizeof(int));
    if (arr == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    int choice, element;
    do
    {
        displayMenu();
        printf("=> Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("=> Enter the element to enqueue: ");
            scanf("%d", &element);
            enqueue(arr, &rear, size, element);
            break;

        case 2:
            dequeue(arr, &front, rear);
            break;

        case 3:
            printf("=> Front element of the queue: %d\n", peek(arr, front, rear));
            break;

        case 4:
            if (isFull(size, rear))
                printf("=> Queue is full\n");
            else
                printf("=> Queue is not full\n");
            break;

        case 5:
            if (isEmpty(front, rear))
                printf("=> Queue is empty\n");
            else
                printf("=> Queue is not empty\n");
            break;

        case 6:
            printf("=> Exiting program.\n");
            break;

        default:
            printf("=> Invalid choice! Please enter a valid option.\n");
        }
    } while (choice != 6);

    free(arr);
}