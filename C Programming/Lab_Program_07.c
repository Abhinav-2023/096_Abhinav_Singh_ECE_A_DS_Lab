/*
Design a C program to implement sparse matrix representation and perform following Operations:
1. createSparseMat(rows, cols): Create a new sparse matrix with the specified number of rows and columns.
2. setValue(row, col, value) : Set the value at the specified row and column.
3. getValue(row, col): Get the value at the specified row and column.
4. addValue(row, col, value): Add the specified value to the existing value at the specified row and column.
5. removeValue(row, col): Remove the value at the specified row and column.
6. getNumRows(): Return the number of rows in the sparse array.
7. getNumCols(): Return the number of columns in the sparse array.
8. transpose(): Return the transpose of the sparse array.
9. multiplyScalar(factor): Multiply each element of the sparse array by the specified scalar factor.
10. add(sparse_array, other_sparse_array): Add another sparse array to this sparse array element-wise.
11. multiply(sparse_array, other_sparse_array): Multiply this sparse array by another sparse array (matrix multiplication).
12. toDenseArray(): Convert the sparse array to a dense array representation.
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int row;
    int col;
    int value;
} Element;

typedef struct {
    int rows;
    int cols;
    int count;
    Element *elements;
} sparse_matrix;

sparse_matrix *create_sparse_matrix(int rows, int cols);
void setValue(sparse_matrix *matrix, int row, int col, int value);
int getValue(sparse_matrix *matrix, int row, int col);
void addValue(sparse_matrix *matrix, int row, int col, int value);
void removeValue(sparse_matrix *matrix, int row, int col);
int getNumberOfRows(sparse_matrix *matrix);
int getNumberOfColumns(sparse_matrix *matrix);
sparse_matrix *transpose(sparse_matrix *matrix);
void multiplyScalar(sparse_matrix *matrix, int factor);
void add(sparse_matrix *matrix, sparse_matrix *other);
sparse_matrix *multiply(sparse_matrix *matrix1, sparse_matrix *matrix2);
int **toDenseArray(sparse_matrix *matrix);
void printMatrix(int **array, int rows, int cols);

sparse_matrix *create_sparse_matrix(int rows, int cols) {
    sparse_matrix *matrix = (sparse_matrix *)malloc(sizeof(sparse_matrix));
    matrix->rows = rows;
    matrix->cols = cols;
    matrix->count = 0;
    matrix->elements = NULL;
    return matrix;
}

void setValue(sparse_matrix *matrix, int row, int col, int value) {
    if (row < 0 || row >= matrix->rows || col < 0 || col >= matrix->cols) {
        printf("Invalid position.\n");
        return;
    }

    for (int i = 0; i < matrix->count; i++) {
        if (matrix->elements[i].row == row && matrix->elements[i].col == col) {
            matrix->elements[i].value = value;
            return;
        }
    }

    matrix->count++;
    matrix->elements = (Element *)realloc(matrix->elements, matrix->count * sizeof(Element));
    matrix->elements[matrix->count - 1].row = row;
    matrix->elements[matrix->count - 1].col = col;
    matrix->elements[matrix->count - 1].value = value;
}

int getValue(sparse_matrix *matrix, int row, int col) {
    for (int i = 0; i < matrix->count; i++) {
        if (matrix->elements[i].row == row && matrix->elements[i].col == col) {
            return matrix->elements[i].value;
        }
    }
    return 0;
}

void addValue(sparse_matrix *matrix, int row, int col, int value) {
    int currentValue = getValue(matrix, row, col);
    setValue(matrix, row, col, currentValue + value);
}

void removeValue(sparse_matrix *matrix, int row, int col) {
    for (int i = 0; i < matrix->count; i++) {
        if (matrix->elements[i].row == row && matrix->elements[i].col == col) {
            for (int j = i; j < matrix->count - 1; j++) {
                matrix->elements[j] = matrix->elements[j + 1];
            }
            matrix->count--;
            matrix->elements = (Element *)realloc(matrix->elements, matrix->count * sizeof(Element));
            return;
        }
    }
}

int getNumberOfRows(sparse_matrix *matrix) {
    return matrix->rows;
}

int getNumberOfColumns(sparse_matrix *matrix) {
    return matrix->cols;
}

sparse_matrix *transpose(sparse_matrix *matrix) {
    sparse_matrix *transposed = create_sparse_matrix(matrix->cols, matrix->rows);

    for (int i = 0; i < matrix->count; i++) {
        setValue(transposed, matrix->elements[i].col, matrix->elements[i].row, matrix->elements[i].value);
    }

    return transposed;
}

void multiplyScalar(sparse_matrix *matrix, int factor) {
    for (int i = 0; i < matrix->count; i++) {
        matrix->elements[i].value *= factor;
    }
}

void add(sparse_matrix *matrix, sparse_matrix *other) {
    if (matrix->rows != other->rows || matrix->cols != other->cols) {
        printf("Matrix dimensions does not match.\n");
        return;
    }

    for (int i = 0; i < other->count; i++) {
        addValue(matrix, other->elements[i].row, other->elements[i].col, other->elements[i].value);
    }
}

sparse_matrix *multiply(sparse_matrix *matrix1, sparse_matrix *matrix2) {
    if (matrix1->cols != matrix2->rows) {
        printf("Matrix dimensions are not valid.\n");
        return NULL;
    }

    sparse_matrix *result = create_sparse_matrix(matrix1->rows, matrix2->cols);
}

int **toDenseArray(sparse_matrix *matrix) {
    int **denseArray = (int **)malloc(matrix->rows * sizeof(int *));
    for (int i = 0; i < matrix->rows; i++) {
        denseArray[i] = (int *)malloc(matrix->cols * sizeof(int));
        for (int j = 0; j < matrix->cols; j++) {
            denseArray[i][j] = getValue(matrix, i, j);
        }
    }
    return denseArray;
}

void printMatrix(int **array, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%d\t", array[i][j]);
        }
        printf("\n");
    }
}

int main(void)
{
    sparse_matrix *matrix1 = create_sparse_matrix(3, 3);
    setValue(matrix1, 0, 0, 1);
    setValue(matrix1, 1, 1, 2);
    setValue(matrix1, 2, 2, 3);

    printf("Original Matrix:\n");
    int **denseArray = toDenseArray(matrix1);
    printMatrix(denseArray, getNumberOfRows(matrix1), getNumberOfColumns(matrix1));
    printf("\n");

    sparse_matrix *transposed = transpose(matrix1);
    printf("Transposed Matrix:\n");
    denseArray = toDenseArray(transposed);
    printMatrix(denseArray, getNumberOfRows(transposed), getNumberOfColumns(transposed));
    printf("\n");

    multiplyScalar(matrix1, 2);
    printf("Matrix after multiplying by scalar:\n");
    denseArray = toDenseArray(matrix1);
    printMatrix(denseArray, getNumberOfRows(matrix1), getNumberOfColumns(matrix1));
    printf("\n");

    sparse_matrix *matrix2 = create_sparse_matrix(3, 3);
    setValue(matrix2, 0, 0, 1);
    setValue(matrix2, 1, 1, 2);
    setValue(matrix2, 2, 2, 3);
    printf("Matrix 2:\n");
    denseArray = toDenseArray(matrix2);
    printMatrix(denseArray, getNumberOfRows(matrix2), getNumberOfColumns(matrix2));
    printf("\n");

    printf("Adding Matrix 2 to Original Matrix:\n");
    add(matrix1, matrix2);
    denseArray = toDenseArray(matrix1);
    printMatrix(denseArray, getNumberOfRows(matrix1), getNumberOfColumns(matrix1));
    printf("\n");

    sparse_matrix *matrix3 = create_sparse_matrix(3, 2);
    setValue(matrix3, 0, 0, 1);
    setValue(matrix3, 0, 1, 2);
    setValue(matrix3, 1, 0, 3);
    setValue(matrix3, 1, 1, 4);
    setValue(matrix3, 2, 0, 5);
    setValue(matrix3, 2, 1, 6);
    printf("Matrix 3:\n");
    denseArray = toDenseArray(matrix3);
    printMatrix(denseArray, getNumberOfRows(matrix3), getNumberOfColumns(matrix3));
    printf("\n");

    printf("Matrix multiplication (Original Matrix x Matrix 3):\n");
    sparse_matrix *result = multiply(matrix1, matrix3);
    denseArray = toDenseArray(result);
    printMatrix(denseArray, getNumberOfRows(result), getNumberOfColumns(result));
    printf("\n");

    printf("Removing value at position (1, 1) from Original Matrix:\n");
    removeValue(matrix1, 1, 1);
    denseArray = toDenseArray(matrix1);
    printMatrix(denseArray, getNumberOfRows(matrix1), getNumberOfColumns(matrix1));
    printf("\n");

    printf("Number of rows in Original Matrix: %d\n", getNumberOfRows(matrix1));
    printf("Number of columns in Original Matrix: %d\n", getNumberOfColumns(matrix1));
    printf("\n");

    free(matrix1->elements);
    free(matrix1);
    free(matrix2->elements);
    free(matrix2);
    free(matrix3->elements);
    free(matrix3);
    free(result->elements);
    free(result);
    free(transposed->elements);
    free(transposed);
    for (int i = 0; i < 3; i++)
        free(denseArray[i]);
    free(denseArray);

}
