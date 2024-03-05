/*
NAME :- ABHINAV SINGH
BRANCH :- ECE
SECTION :- A
ROLL NUMBER :- 2023ECE096
EXAM ROLL NUMBER :- 23294917096
ENROLLMENT NUMBER :- 23DOECBTEC000096
*/

/*
Write a C program to check whether given matrix is sparse matrix or not. If it is, generate sparse matrix with linked list implementation.
*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int rows, cols, value;
    struct Node *next;
};

typedef struct Node Node;

int sparse_matrix(int matrix[][10], int rows, int cols)
{
    int count = 0;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (matrix[i][j] != 0)
                count++;
        }
    }

    if (count > (rows * cols) / 2)
        return 0;
    else
        return 1;
}

Node *create_sparse_matrix(int matrix[][10], int rows, int cols)
{
    Node *head = NULL;

    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            if (matrix[i][j] != 0)
            {
                Node *new_node = (Node *)malloc(sizeof(Node));
                new_node->rows = i;
                new_node->cols = j;
                new_node->value = matrix[i][j];
                new_node->next = NULL;

                if (head == NULL)
                    head = new_node;
                else
                {
                    Node *temp = head;
                    while (temp->next != NULL)
                        temp = temp->next;
                    temp->next = new_node;
                }
            }
        }
    }

    return head;
}

void display_sparse_matrix(Node *head)
{
    Node *temp = head;
    printf("Row\tColumn\tValue\n");

    while (temp != NULL)
    {
        printf("%d\t%d\t%d\n", temp->rows, temp->cols, temp->value);
        temp = temp->next;
    }
}

int main()
{
    int matrix[10][10], rows, cols;

    printf("Enter number of rows and columns of matrix: ");
    scanf("%d %d", &rows, &cols);

    printf("Enter elements of matrix:\n");
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            scanf("%d", &matrix[i][j]);
        }
    }

    printf("The matrix: \n");
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < cols; ++j)
        {
            printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }

    if (sparse_matrix(matrix, rows, cols))
    {
        printf("The given matrix is sparse.\n");
        Node *sparse_matrix = create_sparse_matrix(matrix, rows, cols);
        printf("Sparse matrix representation:\n");
        display_sparse_matrix(sparse_matrix);
    }
    else
    {
        printf("The given matrix is not sparse.\n");
    }

    return 0;
}
