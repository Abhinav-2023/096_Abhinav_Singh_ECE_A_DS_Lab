/*
NAME :- ABHINAV SINGH
BRANCH :- ECE
SECTION :- A
ROLL NUMBER :- 2023ECE096
EXAM ROLL NUMBER :- 23294917096
ENROLLMENT NUMBER :- 23DOECBTEC000096
*/

/*
Write a C program to check whether given matrix is sparse matrix or not. If it is, generate sparse matrix with array implementation.
*/

#include <stdio.h>

void input_matrix(int matrix[10][10], int rows, int cols)
{
    printf("Enter the elements of the matrix: \n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &matrix[i][j]);
        }
    }
}

void display_matrix(int matrix[10][10], int rows, int cols)
{
    printf("The matrix is: \n");
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            printf(" %d", matrix[i][j]);
        }
        printf("\n");
    }
}

int sparse_matrix(int matrix[10][10], int rows, int cols)
{
    int zeros_count = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] == 0)
                zeros_count++;
        }
    }
    return (zeros_count > (rows * cols) / 2);
}

void generate_sparse_matrix(int matrix[10][10], int rows, int cols)
{
    int sparse_matrix[10][3];
    int k = 0;
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            if (matrix[i][j] != 0)
            {
                sparse_matrix[k][0] = i;
                sparse_matrix[k][1] = j;
                sparse_matrix[k][2] = matrix[i][j];
                k++;
            }
        }
    }
    printf("\n The sparse matrix is: \n");
    printf(" Row\tColumn\tValue\n");
    for (int i = 0; i < k; i++)
    {
        printf("%d\t%d\t%d\n", sparse_matrix[i][0], sparse_matrix[i][1], sparse_matrix[i][2]);
    }
}

int main()
{
    int matrix[10][10];
    int rows, cols;

    printf("Enter the no. of rows and columns of the matrix: ");
    scanf("%d %d", &rows, &cols);

    input_matrix(matrix, rows, cols);
    display_matrix(matrix, rows, cols);

    if (sparse_matrix(matrix, rows, cols))
    {
        printf("The given matrix is a sparse matrix.\n");
        generate_sparse_matrix(matrix, rows, cols);
    }
    else
    {
        printf("The given matrix is not a sparse matrix.\n");
    }

    return 0;
}
