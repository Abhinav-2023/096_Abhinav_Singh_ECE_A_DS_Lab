/*
NAME :- ABHINAV SINGH
BRANCH :- ECE
SECTION :- A
ROLL NUMBER :- 2023ECE096
EXAM ROLL NUMBER :- 23294917096
ENROLLMENT NUMBER :- 23DOECBTEC000096
*/

/*
Implement Queue ADT and perform its operations in C using structure
*/

#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int size;
    int front;
    int rear;
    int *arr;
};

int isFull(struct queue *q)
{
    return (q->rear == q->size - 1);
}

int isEmpty(struct queue *q)
{
    return (q->rear == q->front);
}

void displayQueue(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("Empty\n");
        return;
    }
    for (int i = q->front + 1; i <= q->rear; i++)
    {
        printf("%d ", q->arr[i]);
    }
    printf("\n");
}

void enqueue(struct queue *q, int val)
{
    if (isFull(q))
        printf("=> Queue Overflow\n");
    else
    {
        q->arr[++q->rear] = val;
        printf("=> Enqueued element: %d\n", val);
        printf("=> Current Queue: ");
        displayQueue(q);
    }
}

int dequeue(struct queue *q)
{
    int val = -1;
    if (isEmpty(q))
    {
        printf("=> Queue Underflow\n");
    }
    else
    {
        val = q->arr[++q->front];
        printf("=> Dequeued element: %d\n", val);
    }
    return val;
}

int peek(struct queue *q)
{
    if (isEmpty(q))
    {
        printf("=> Queue is empty\n");
        return -1; 
    }
    else
    {
        return q->arr[q->front + 1]; 
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
    struct queue *q = (struct queue*)malloc(sizeof(struct queue));

    if (q == NULL)
    {
        printf("Memory allocation failed\n");
        return 1;
    }

    printf("=> Enter the size of the queue: ");
    scanf("%d", &(q->size));

    q->front = -1;
    q->rear = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

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
            enqueue(q, element);
            break;

        case 2:
            dequeue(q);
            break;

        case 3:
            printf("=> Front element of the queue: %d\n", peek(q));
            break;

        case 4:
            if (isFull(q))
                printf("=> Queue is full\n");
            else
                printf("=> Queue is not full\n");
            break;

        case 5:
            if (isEmpty(q))
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

    free(q->arr);
    free(q);
}