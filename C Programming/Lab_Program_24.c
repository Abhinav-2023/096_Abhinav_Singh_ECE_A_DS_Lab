/*
NAME :- ABHINAV SINGH
BRANCH :- ECE
SECTION :- A
ROLL NUMBER :- 2023ECE096
EXAM ROLL NUMBER :- 23294917096
ENROLLMENT NUMBER :- 23DOECBTEC000096
*/

/*
Implement Queue ADT and  its operation using Linked List.
*/
#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
}*front = NULL, *rear = NULL;

void enQueue(struct Node *t,int x)
{
    t = (struct Node *)malloc(sizeof(struct Node));
    if( t == NULL)
    {
        printf("Queue is full.\n");
    }
    else
    {
        t->data = x;
        t->next = NULL;
        if(front == NULL)
        {
            front= rear = t;
        }
        else
        {
            rear->next = t;
            rear = t;
        }
    }
}

int deQueue(struct Node *t)
{
    int x = -1;
    if(front == NULL)
    {
        printf("Queue is Empty.\n");
    }
    else
    {
        x = front->data;
        t = front;
        front = front->next;
        free(t);
    }
    return x;
}

void display()
{
    struct Node *p = front;
    while(p)
    {
        printf("%d ",p ->data);
        p = p->next;
    }
    printf("\n");
}

int main(void)
{
    int choice , x, p ,t;
    do
    {
        printf("1.enQueue\n");
        printf("2.deQueue\n");
        printf("3.Display\n");
        printf("4.Exit\n");
        printf("=> Enter your choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter element to enQueue: ");
                scanf("%d", &x);
                enQueue(&p,x);
                break;
            case 2:
                printf("deQueued element: %d\n",deQueue(&p));
                break;
            case 3:
                display(p);
                break;
            case 4:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    while(choice != 4);
}