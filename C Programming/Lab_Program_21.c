/*
NAME :- ABHINAV SINGH
BRANCH :- ECE
SECTION :- A
ROLL NUMBER :- 2023ECE096
EXAM ROLL NUMBER :- 23294917096
ENROLLMENT NUMBER :- 23DOECBTEC000096
*/

/*
Implement the ADT of Circular Linked List using C. Perform its all operations.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

struct Node *createNode(int data)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

void insertAtBeginning(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        newNode->next = newNode;
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
        *head = newNode;
    }
    printf("Node inserted at the beginning successfully.\n");
}

void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        newNode->next = newNode;
        *head = newNode;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->next = *head;
    }
    printf("Node inserted at the end successfully.\n");
}

void insertAfter(struct Node **head, int key, int data)
{
    struct Node *newNode = createNode(data);
    struct Node *temp = *head;
    do
    {
        if (temp->data == key)
        {
            newNode->next = temp->next;
            temp->next = newNode;
            printf("Node inserted after %d successfully.\n", key);
            return;
        }
        temp = temp->next;
    } while (temp != *head);
    printf("Element %d not found in the list.\n", key);
}

void deleteFirst(struct Node **head)
{
    if (*head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if ((*head)->next == *head)
    {
        free(*head);
        *head = NULL;
    }
    else
    {
        struct Node *temp = *head;
        while (temp->next != *head)
        {
            temp = temp->next;
        }
        temp->next = (*head)->next;
        struct Node *delNode = *head;
        *head = (*head)->next;
        free(delNode);
    }
    printf("First node deleted successfully.\n");
}

void deleteNode(struct Node **head, int key)
{
    if (*head == NULL)
    {
        printf("List is empty. Nothing to delete.\n");
        return;
    }
    if ((*head)->data == key)
    {
        deleteFirst(head);
        return;
    }
    struct Node *prev = NULL;
    struct Node *curr = *head;
    do
    {
        if (curr->data == key)
        {
            prev->next = curr->next;
            free(curr);
            printf("Node with data %d deleted successfully.\n", key);
            return;
        }
        prev = curr;
        curr = curr->next;
    } while (curr != *head);
    printf("Element %d not found in the list.\n", key);
}

void display(struct Node *head)
{
    struct Node *temp = head;
    if (temp == NULL)
    {
        printf("List is empty.\n");
        return;
    }
    printf("Circular Linked List: ");
    do
    {
        printf("%d -> ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("HEAD\n");
}

int main()
{
    struct Node *head = NULL;
    int choice, data, key;

    while (1)
    {
        printf("\nCircular Linked List Operations:\n");
        printf("1. Insert at the beginning\n");
        printf("2. Insert at the end\n");
        printf("3. Insert after a specific element\n");
        printf("4. Delete the first node\n");
        printf("5. Delete a specific element\n");
        printf("6. Display\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter data to insert at the beginning: ");
            scanf("%d", &data);
            insertAtBeginning(&head, data);
            break;
        case 2:
            printf("Enter data to insert at the end: ");
            scanf("%d", &data);
            insertAtEnd(&head, data);
            break;
        case 3:
            printf("Enter the element after which you want to insert: ");
            scanf("%d", &key);
            printf("Enter data to insert after %d: ", key);
            scanf("%d", &data);
            insertAfter(&head, key, data);
            break;
        case 4:
            deleteFirst(&head);
            break;
        case 5:
            printf("Enter the element to delete: ");
            scanf("%d", &key);
            deleteNode(&head, key);
            break;
        case 6:
            display(head);
            break;
        case 7:
            printf("Exiting...\n");
            exit(0);
        default:
            printf("Invalid choice! Please enter a valid choice.\n");
        }
    }

    return 0;
}
