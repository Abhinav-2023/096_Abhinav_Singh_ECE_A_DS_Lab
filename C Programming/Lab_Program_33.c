/*
NAME :- ABHINAV SINGH
BRANCH :- ECE
SECTION :- A
ROLL NUMBER :- 2023ECE096
EXAM ROLL NUMBER :- 23294917096
ENROLLMENT NUMBER :- 23DOECBTEC000096
*/

/*
implementation of Binary search Tree (create, search, insert, delete, finding maximum/minimum by both ways that were done in class)
*/
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
} Node;

Node *createNode(int data)
{
    Node *newNode = (Node *)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

Node *insert(Node *root, int data)
{
    if (root == NULL)
    {
        return createNode(data);
    }
    if (data < root->data)
    {
        root->left = insert(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = insert(root->right, data);
    }
    return root;
}

Node *search(Node *root, int data)
{
    if (root == NULL || root->data == data)
    {
        return root;
    }
    if (data < root->data)
    {
        return search(root->left, data);
    }
    else
    {
        return search(root->right, data);
    }
}

Node *findMin(Node *root)
{
    while (root && root->left != NULL)
    {
        root = root->left;
    }
    return root;
}

Node *findMax(Node *root)
{
    while (root && root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

Node *deleteNode(Node *root, int data)
{
    if (root == NULL)
    {
        return root;
    }
    if (data < root->data)
    {
        root->left = deleteNode(root->left, data);
    }
    else if (data > root->data)
    {
        root->right = deleteNode(root->right, data);
    }
    else
    {
        if (root->left == NULL)
        {
            Node *temp = root->right;
            free(root);
            return temp;
        }
        else if (root->right == NULL)
        {
            Node *temp = root->left;
            free(root);
            return temp;
        }
        Node *temp = findMin(root->right);
        root->data = temp->data;
        root->right = deleteNode(root->right, temp->data);
    }
    return root;
}

void inorder(Node *root)
{
    if (root != NULL)
    {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

int main()
{
    Node *root = NULL;
    int choice, value;
    Node *result;

    while (1)
    {
        printf("\nMenu:\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Find Minimum\n");
        printf("5. Find Maximum\n");
        printf("6. Inorder Traversal\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            printf("Enter value to insert: ");
            scanf("%d", &value);
            root = insert(root, value);
            break;
        case 2:
            printf("Enter value to search: ");
            scanf("%d", &value);
            result = search(root, value);
            if (result != NULL)
            {
                printf("Value %d found in the tree.\n", value);
            }
            else
            {
                printf("Value %d not found in the tree.\n", value);
            }
            break;
        case 3:
            printf("Enter value to delete: ");
            scanf("%d", &value);
            root = deleteNode(root, value);
            break;
        case 4:
            result = findMin(root);
            if (result != NULL)
            {
                printf("Minimum value in the tree: %d\n", result->data);
            }
            else
            {
                printf("The tree is empty.\n");
            }
            break;
        case 5:
            result = findMax(root);
            if (result != NULL)
            {
                printf("Maximum value in the tree: %d\n", result->data);
            }
            else
            {
                printf("The tree is empty.\n");
            }
            break;
        case 6:
            printf("Inorder Traversal: ");
            inorder(root);
            printf("\n");
            break;
        case 7:
            exit(0);
            break;
        default:
            printf("Invalid choice!\n");
        }
    }

    return 0;
}
