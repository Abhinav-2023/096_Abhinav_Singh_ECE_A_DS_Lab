/*
Write menu-driven program in C to input 1D array (static) and perform following operations:
a. Linear search for an element.
b. Inserting an element at specified position.
c .Deleting an element from the specified position.
d. Reversing the array.
e. Updating the array , multiply the odd-indexed elements by 2 and adding 5 to all the elements at even index.
*/

#include <stdio.h>

#define MAX_SIZE 100

void linear_search(int arr[], int size, int key)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == key)
        {
            printf("Element %d is at index %d\n", key, i);
            return;
        }
    }
    printf("Element %d is not found in the array\n", key);
}

void insert_element(int arr[], int *size, int position, int element)
{
    if (*size >= MAX_SIZE)
    {
        printf("Array is full, cannot insert more elements\n");
        return;
    }
    if (position < 0 || position > *size)
    {
        printf("Invalid position to insert element\n");
        return;
    }
    for (int i = *size; i > position; i--)
    {
        arr[i] = arr[i - 1];
    }
    arr[position] = element;
    (*size)++;
}

void delete_element(int arr[], int *size, int position)
{
    if (*size <= 0)
    {
        printf("Array is emepty, cannot delete element\n");
        return;
    }
    if (position < 0 || position >= *size)
    {
        printf("Invalid position to delete element\n");
        return;
    }
    for (int i = position; i < *size - 1; i++)
    {
        arr[i] = arr[i + 1];
    }
    (*size)--;
}

void reverse_array(int arr[], int size)
{
    int start = 0, end = size - 1;
    while (start < end)
    {
        int temp = arr[start];
        arr[start] = arr[end];
        arr[end] = temp;
        start++;
        end--;
    }
}

void update_array(int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        if (i % 2 == 0)
            arr[i] += 5;
        else
            arr[i] *= 2;
    }
}

int main()
{
    int arr[MAX_SIZE], size = 0, element, position, key;
    char choice;
    
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }

    while(choice != 'f')
    {

        printf("Menu:\n");
        printf("a. Linear search for an element\n");
        printf("b. Insert an element at specified position\n");
        printf("c. Delete an element from specified postition\n");
        printf("d. Reverse the array\n");
        printf("e. Update the array\n");
        printf("f. Exit\n");

        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch (choice)
        {
            case 'a':
                printf("Enter the element to search: ");
                scanf("%d", &key);
                linear_search(arr, size, key);
                break;
            case 'b':
                printf("Enter the element to insert: ");
                scanf("%d", &position);
                printf("Enter the position to insert: ");
                scanf("%d", &position);
                insert_element(arr, &size, position, element);
                break;
            case 'c':
                printf("Enter the position to delete: ");
                scanf("%d", &position);
                delete_element(arr, &size, position);
                break;
            case 'd':
                reverse_array(arr, size);
                printf("Array reversed successfully\n");
                break;
            case 'e':
                update_array(arr, size);
                printf("Array updated successfully\n");
                break;
            case 'f':
                printf("Exiting\n");
                break;
            default:
                printf("Invalid choice\n");
        }

        printf("Array after operation:\n");
        for (int i = 0; i < size; i++)
        {
            printf(" %d ", arr[i]);
        }
        printf("\n");
    }

    return 0;
}